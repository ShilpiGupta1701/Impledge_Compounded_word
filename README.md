# Impledge_Compounded_word
# Overview
By identifying the longest and second-longest compound words among a list of words supplied in an input file, this C++ program solves the Word Composition Problem. The program finds compound words quickly by using a Trie data structure.
# Execution Steps
1. Take a copy of this repository locally.
2. Launch the project in Visual Studio,Code blocks or any other C++ development environment.
3. Once the compoundedWord.cpp code has been compiled and executed, make sure you have a C++ compiler installed.
4. The source code and input files need to be located in the same directory.
5. Depending on your needs, change the input file name on line 127 of the compoundedWord.cpp file to input_01.txt or input_02.txt.
6. When the program is run, the output will be seen on the console.
# Approach
1. Using a custom comparator, the program first sorts the input words according to length in ascending order.
2. After removing the longest word from the sorted list and determining if it can be created from other words in the list, repeatedly finds the longest compound word.
3. To determine the second longest compound word, the program goes through this process again.
# Execution
1. I have created a class called LongestCompoundWordFinder that has all the functionalities needed by the application.
2. The application reads the input from the designated input file and stores it as a vector.
3. The longest and second-longest compound words can be found using the findLongestCompoundWords function.
4. Words are organized and searched for quickly using a Trie data structure.
5. The program assigns flags to words in order to monitor their suitability for compound word construction.
# Time Complexity
In most real-world scenarios, the average time complexity of this solution can be roughly expressed as O(N * L), where N is the total number of words in the input and L is the average word length.
# Code Execution Flow
1. To efficiently store and manage words, the code first defines a Trie data structure. It initializes the Trie's root.
2. Using the insertingWord function, the program takes words from an input file ("Input_02.txt") and inserts them into the Trie data structure. It goes through the Trie for every word, adding nodes to represent it as necessary.
3. Following the entry of every word into the Trie, the wordCompare and the sort function are used to rank the list of words according to their lengths and lexicographic order.
4. The sorted list of words is iterated over by the program, which begins with an empty resultant vector. Every word is added to the resultant vector, and the Trie is used to determine whether the word is a compound word. It recursively examines the Trie to see whether a word can be divided into smaller words in order to determine if it is a compound word.
5. The longest and second-longest compound words discovered during the iteration are identified by the program and displayed.
6. The code calculates the elapsed time and logs the start and end times of the Trie-based compound word searching procedure.
7. The longest and second-longest compound words the software found are finally printed, together with the amount of time it took to process the input file.
