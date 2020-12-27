#include "wordFunc.h"

/* [Optional] Anagram Functions */

// return true if text and words[index] form an anagram, false otherwise
bool isAna(const char text[], const Word words[], const int index){
    int count2=0;
    int count_index=0;
    int indexes[MAX_TEXT_LENGTH];
    if (strlen(text)!=strlen(words[index].text)){
        return false;
    }
    
    for (int i=0;i<strlen(text);i++){
        for (int k=0; k<strlen(words[index].text);k++){
            if (text[i]==words[index].text[k] && check_indexes(indexes, k, count_index)){
                count2++;
                indexes[count_index]=k;
                count_index++;
                break;
            }
        }
    }
    
    if (count2!=strlen(words[index].text)){
        return false;
    }
    
    return true;
}

bool check_indexes(const int indexes[], int index, int size){
    for (int i=0;i<size;i++){
        if (index==indexes[i]){
            return false;
        }
    }
    return true;
}



// return total no. of anagram(s), and store word index(es) in results[]
int getAna(const char text[], const Word words[], const int currentSize, int results[]){
    int count_ana=0;
    for (int i=0;i<currentSize;i++){
        if (isAna(text, words, i)){
            results[count_ana]=i;
            count_ana++;
        }
    }
    return count_ana;
}
