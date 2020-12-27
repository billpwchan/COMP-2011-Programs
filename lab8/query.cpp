#include "wordFunc.h"


/* Query Functions */

// return index of the word with text[], -1 if not exist
int queryByText(const char text[], const Word words[], const int currentSize){
    for (int i=0;i<currentSize;i++){
        if (strcmp(text,words[i].text)==0){
            return i;
        }
    }
    return -1;
}

// return total no. of match(es), and store word index(es) in results[]
int queryByType(const WordType type, const Word words[], const int currentSize, int results[]){
    int count=0;
    for (int i=0;i<currentSize;i++){
        if (words[i].type==type){
            results[count]=i;
            count++;
        }
    }
    return count;
}
