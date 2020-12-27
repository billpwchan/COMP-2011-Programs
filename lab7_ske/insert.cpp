#include "wordFunc.h"

/* Insert Function */

// insert word into dictionary without breaking lexicological order
void insertWord(const char text[], const char meaning[], const WordType type, Word words[], int &currentSize){
    int count_index=0;
    for (int i=0; i<currentSize;i++){
        if (strcmp(text,words[i].text)<0){
            count_index=i;
            break;
        }
    }
    
    for (int i=++currentSize;i>count_index;i--){
        strcpy(words[i].text, words[i-1].text);
    }
    
    strcpy(words[count_index].text,text);

}
