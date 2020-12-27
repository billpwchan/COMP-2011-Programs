#include <iostream>
#include <cstring>
#include "word.h"

using namespace std;

/* Print Functions */

// Print a word in the specified format
void printWord(const Word words[], const int index);

// Print all words in the dictionary
void printDic(const Word words[], const int currentSize);

// Print words with indexes in results[]
void printResult(const Word words[], const int results[], const int resultSize);



/* Query Functions */

// return index of the word with text[], -1 if not exist
int queryByText(const char text[], const Word words[], const int currentSize);

// return total no. of match(es), and store word index(es) in results[]
int queryByType(const WordType type, const Word words[], const int currentSize, int results[]);



/* Insert Function */

// insert word into dictionary without breaking lexicological order
void insertWord(const char text[], const char meaning[], const WordType type, Word words[], int &currentSize);



/* Palindrome Functions */

// return true if words[index] is a palindrome, false otherwise
bool isPal(const Word words[], const int index);

// return total no. of palindrome(s), and store word index(es) in results[]
int getPal(const Word words[], const int currentSize, int results[]);



/* [Optional] Anagram Functions */

// return true if text and words[index] form an anagram, false otherwise
bool isAna(const char text[], const Word words[], const int index);

// return total no. of anagram(s), and store word index(es) in results[]
int getAna(const char text[], const Word words[], const int currentSize, int results[]);

//return true when the index is not in the indexes array
bool check_indexes(const int indexes[], int index, int size);
