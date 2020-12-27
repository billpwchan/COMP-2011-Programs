#include "wordFunc.h"

/* Insert Function */

// insert word into dictionary without breaking lexicological order
void insertWord(const char text[], const char meaning[], const WordType type, Word words[], int &currentSize){
    int count_index=++currentSize;
    for (int i=0; i<currentSize;i++){
        if (strcmp(words[i].text,text)>0){
            count_index=i;
            break;
        }
        count_index=i;
    }
    
    for (int i=++currentSize;i>count_index;i--){
        strcpy(words[i].text, words[i-1].text);
        strcpy(words[i].meaning, words[i-1].meaning);
        words[i].type=words[i-1].type;
    }
    
    strcpy(words[count_index].text,text);
    strcpy(words[count_index].meaning, meaning);
    words[count_index].type=type;

}
