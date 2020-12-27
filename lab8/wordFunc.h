#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

/* Word Structure */

/* Enum */
enum WordType {noun, verb, adjective, adverb};

/* Constants */
const int MAX_TEXT_LENGTH = 21;
const int MAX_MEANING_LENGTH = 101;
const int MAX_WORD_NUMBER = 50;
const char wordTypeMap[][20]={"noun","verb","adjective","adverb"};

/* Structure */
struct Word{
    char text[MAX_TEXT_LENGTH], meaning[MAX_MEANING_LENGTH];
    WordType type;
};

const int MAX_FILENAME_LENGTH = 50;
const int MAX_LINE_LENGTH = 1000;
const char LINE_DELIM = '\n';
const char WORD_DELIM = '\t';
const int MAX_FILE_WORD_LENGTH = 100;

// read dictionary entries from an external file and store the entries in words array
void readExternalDictionary(const char file[], Word words[], int* currentSize);

// write dictionary entries in the program to an external file
void writeExternalDictionary(const char file[], const Word words[], const int currentSize);

// read a paragraph and store the words one by one uniquely in the newWords array
void readExternalFile(const char file[], char newWords[][MAX_TEXT_LENGTH], int* numOfNewWords);

// print information about the input paragraph
void printInfo(const Word words[], const int currentSize, const char newWords[][MAX_TEXT_LENGTH], const int numOfNewWords);




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
