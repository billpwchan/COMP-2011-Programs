#include "wordFunc.h"

/* Print Functions */

// Print a word in the specified format
void printWord(const Word words[], const int index){
    cout.width(3); cout<<index;
	cout.width(MAX_TEXT_LENGTH); cout << words[index].text<<"  [";
	cout.width(9); cout << wordTypeMap[words[index].type]<<"]  ";
	cout << words[index].meaning<<endl;

}

// Print all words in the dictionary
void printDic(const Word words[], const int currentSize){

	for (int i=0;i<currentSize;i++){
		printWord(words, i);
	}

}

// Print words with indexes in results[]
void printResult(const Word words[], const int results[], const int resultSize){
	for(int i=0;i<resultSize;i++)
		printWord(words,results[i]);
}
