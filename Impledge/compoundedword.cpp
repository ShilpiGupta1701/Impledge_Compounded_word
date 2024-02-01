#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Structure Trie nodes
struct TrieNode {
    TrieNode* childs[26]; // array to store child nodes for each character
    bool isEnd;      // Flag to mark the end of a valid word

    // Checking if the node has a child with character 'ch'
    bool hasChildren(char ch) {
        return childs[ch - 'a'] != NULL;
    }

    // Get the child node with character 'ch'
    TrieNode* getChildren(char ch) {
        return childs[ch - 'a'];
    }

    void insert(char ch, TrieNode* childNode) {
        childs[ch - 'a'] = childNode;
    }

    // Check if the current node marks the end of a word
    bool End() {
        return isEnd;
    }

    // Set the current node as the end of a word
    void setEnd() {
        isEnd = true;
    }

    // Unset the current node as the end of a word
    void unsetEnd() {
        isEnd = false;
    }
};

// Defining a class for finding the longest compound words
class CompoundWordFinder {
    TrieNode* root;

public:
    CompoundWordFinder() {
        root = new TrieNode();
    }

    // Comparator for sorting words based on length
    static bool wordCompare(string a, string b) {
        if (a.length() == b.length()) {
            return a < b;
        }
        return a.length() > b.length();
    }

    // Inserting word into the Trie
    void insertingWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->hasChildren(word[i])) {
                node->insert(word[i], new TrieNode());
            }
            node = node->getChildren(word[i]);
        }
        node->setEnd();
    }

    // Recursively reset the end flag of Trie nodes for a given word
    void resetFlag(string str, int index, TrieNode* tempNode) {
        if (index == str.length()) {
            tempNode->unsetEnd();
            return;
        }
        resetFlag(str, index + 1, tempNode->getChildren(str[index]));
    }

    // Recursively checking if a given word is a compound word
    bool isCompounded(string str, int index, TrieNode* tempNode) {
        if (index == str.length()) {
            return tempNode->End();
        }
        if (tempNode->End()) {
            if (isCompounded(str, index, root)) {
                return true;
            }
        }
        if (tempNode->hasChildren(str[index])) {
            return isCompounded(str, index + 1, tempNode->getChildren(str[index]));
        }
        else {
            return false;
        }
    }

    // Find and display the longest and second-longest compound words
    void findLongestCompoundWords(vector<string>& words) {
        vector<string> resultant;
        for (int i = 0; i < words.size(); i++) {
            resultant.push_back(words[i]);
            insertingWord(words[i]);
        }
        sort(resultant.begin(), resultant.end(), wordCompare);
        string longestCompound = "", secondLongestCompound = "";
        for (int i = 0; i < resultant.size(); i++) {
            resetFlag(resultant[i], 0, root);
            if (isCompounded(resultant[i], 0, root)) {
                if (longestCompound.empty()) {
                    longestCompound = resultant[i];
                }
                else {
                    secondLongestCompound = resultant[i];
                    break;
                }
            }
            insertingWord(resultant[i]);
        }
        cout << "Longest Compound Word: " << longestCompound << endl;
        cout << "Second Longest Compound Word: " << secondLongestCompound << endl;
    }
};

int main() {
    CompoundWordFinder finder;
    fstream file;
    vector<string> wordList;
    file.open("Input_02.txt", ios::in);
    if (file.fail()) {
        cout << "Failed to open the file.";
    }
    else {
        string word;
        while (file >> word) {
            wordList.push_back(word);
        }
        file.close();

        auto startTime = high_resolution_clock::now();
        finder.findLongestCompoundWords(wordList);
        auto endTime = high_resolution_clock::now();
        auto elapsedTime = duration_cast<milliseconds>(endTime - startTime); // Calculate elapsed time
        cout << "Time taken to process the input file: " << elapsedTime.count() << " milliseconds" << endl;
    }
    return 0;
}
