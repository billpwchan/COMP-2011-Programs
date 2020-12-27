#include "wordFunc.h"

/* Palindrome Functions */

// return true if words[index] is a palindrome, false otherwise
bool isPal(const Word words[], const int index){
    int length=static_cast<int>(strlen(words[index].text));
    for (int i=0;i<(length-1-i);i++){
        if (words[index].text[i]!=words[index].text[length-1-i]){
            return false;
        }
    }
    return true;
}

// return total no. of palindrome(s), and store word index(es) in results[]
int getPal(const Word words[], const int currentSize, int results[]){
    int count_pal=0;
    for (int i=0;i<currentSize;i++){
        if (isPal(words, i)){
            results[count_pal]=i;
            count_pal++;
        }
    }
    return count_pal;
}
