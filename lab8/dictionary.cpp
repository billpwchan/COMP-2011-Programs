#include <iostream>
#include <cstring>
#include "wordFunc.h"

using namespace std;

int main() 
{
    // Initial Dictionary
    Word words[MAX_WORD_NUMBER];

    // Maintain current no. of words
    int currentSize = 0;

    // For input/output
    char fileName[MAX_FILENAME_LENGTH];

    int option;
    do 
    {
        // For paragraph input
        char newWords[MAX_FILE_WORD_LENGTH][MAX_TEXT_LENGTH]={};
        int numOfWords = 0;

        // Menu
        cout << endl << "Welcome to the dictionary!" << endl << endl;
        cout << "You have the following options:" << endl;
        cout << " (0) Import dictionary from an external file" << endl;
        cout << " (1) Print current dictionary" << endl;
        cout << " (2) Query by text" << endl;
        cout << " (3) Query by type" << endl;
        cout << " (4) Insert a new word" << endl;
        cout << " (5) Get palindrome(s)" << endl;
        cout << " (6) Get anagram(s) with a text" << endl;
        cout << " (7) Check sentences from an external file" << endl;
        cout << " (8) Export dictionary to an external file" << endl;
        cout << " (9) Quit" << endl << endl;

        // Validate option
        do 
        {
            cout << "Please enter an option (0-9) to proceed: ";
            cin >> option;
            cin.ignore();
            if(option<0||option>9) cout << "Invalid option. Please try again." << endl;
        } while(option<0||option>9);


        switch(option)
        {
        case 0: // Read words from an external file
            cout << "Please enter the filename: ";
            cin >> fileName;
            cin.ignore();
            readExternalDictionary(fileName, words, &currentSize);
            break;

        case 1: // Print current dictionary
            cout << endl << "Current dictionary size = " << currentSize << endl;
            printDic(words, currentSize);
            cout << endl;
            break;

        case 2: // Query by text
            char text[MAX_TEXT_LENGTH];
            int resultIndex;

            cout << "Please enter text (max = " << MAX_TEXT_LENGTH << " characters): ";
            cin.getline(text, MAX_TEXT_LENGTH);

            resultIndex=queryByText(text, words, currentSize);

            if(resultIndex!=-1){
                cout << endl << "Found matched word: " << endl;
                printWord(words, resultIndex);
                cout << endl;
            }
            else cout << "The word \"" << text << "\" does not exist." << endl;
            break;

        case 3: // Query by type
            int type, results[MAX_WORD_NUMBER], resultSize;

            // Validate word type
            do {
                cout << "Please enter word type number [(0) noun (1) verb (2) adjective (3) adverb]: ";
                cin >> type;
                cin.ignore();
                if(type<0||type>3) cout << "Invalid type. Please try again." << endl;
            } while(type<0||type>3);

            resultSize=queryByType(WordType(type), words, currentSize, results);

            if(resultSize){
                cout << endl << "Found " << resultSize << " matched word(s) in total: " << endl;
                printResult(words, results, resultSize);
                cout << endl;
            }
            else cout << "There is no " << wordTypeMap[type] << " in the dictionary." << endl;
            break;

        case 4: // Insert a new word
            char meaning[MAX_MEANING_LENGTH];

            // Check if word already exists
            do {
                cout << "Please enter text (max = " << MAX_TEXT_LENGTH << " characters): ";
                cin.getline(text, MAX_TEXT_LENGTH);

                resultIndex = queryByText(text, words, currentSize);
                if(resultIndex!=-1)
                    cout << "Word already exists. Please try again." << endl;
            } while(resultIndex!=-1);

            cout << "Please enter meaning (max = " << MAX_MEANING_LENGTH << " characters): ";
            cin.getline(meaning, MAX_MEANING_LENGTH);

            // Validate word type
            do {
                cout << "Please enter word type number [(0) noun (1) verb (2) adjective (3) adverb]: ";
                cin >> type;
                cin.ignore();
                if(type<0||type>3) cout << "Invalid type. Please try again." << endl;
            } while(type<0||type>3);
                
            insertWord(text,meaning, WordType(type), words, currentSize);
            cout << "Insertion is successful." << endl;
            break;

        case 5: // Get palindrome(s)
            resultSize=getPal(words, currentSize, results);

            if(resultSize){
                cout << endl << "Found " << resultSize << " palindrome(s) in total: " << endl;
                printResult(words, results, resultSize);
                cout << endl;
            }
            else cout << "There is no palindrome in the dictionary." << endl;
            break;

        case 6: // Get anagram(s) with a text
            cout << "Please enter text (max = " << MAX_TEXT_LENGTH << " characters): ";
            cin.getline(text, MAX_TEXT_LENGTH);
            
            resultSize=getAna(text, words, currentSize, results);

            if(resultSize){
                cout << endl << "Found " << resultSize << " anagram(s) in total: " << endl;
                printResult(words, results, resultSize);
                cout << endl;
            }
            else cout << "There is no anagram in the dictionary." << endl;
            break;

        case 7: // read paragraphs from an external file and generate a report about the spelling mistakes
            cout << "Please enter the filename: ";
            cin >> fileName;
            cin.ignore();
            readExternalFile(fileName, newWords, &numOfWords);
            cout << endl;
            printInfo(words, currentSize, newWords, numOfWords);
            break;

        case 8: // Export dictionary
            cout << "Please enter the filename: ";
            cin >> fileName;
            cin.ignore();
            writeExternalDictionary(fileName, words, currentSize);
            break;

        }

    } while(option!=9);

    return 0;
}
