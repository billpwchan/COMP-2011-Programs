#include "wordFunc.h"


// read dictionary entries from an external file and store the entries in words array
void readExternalDictionary(const char file[], Word words[], int* currentSize) {

    if (strlen(file) > MAX_FILENAME_LENGTH) {
        cout << "The file name is too long. Please try again.";
        return;
    }

    ifstream ifs;
    ifs.open(file);

    if (!ifs) {
        cerr << "Error: Can't open \"" << file << "\"\n"; return;
    }

    char* temp_string = new char [MAX_LINE_LENGTH];
    char* text = new char [MAX_TEXT_LENGTH];
    char* meaning = new char [MAX_MEANING_LENGTH];
    char* wordtype = new char[20];
    WordType temp_type = WordType(0);

    while (!ifs.eof()) {
        ifs.getline(temp_string, MAX_LINE_LENGTH, LINE_DELIM);

        int current_size = *currentSize;
        int main_count = 0, count1 = 0, count2 = 0, count3 = 0;
        while (temp_string[count1] != WORD_DELIM) {
            text[main_count++] = temp_string[count1++];
        }
        text[main_count] = '\0';
        count2 = count1 + 1;
        main_count = 0;
        while (temp_string[count2] != WORD_DELIM) {
            meaning[main_count++] = temp_string[count2++];
        }
        meaning[main_count] = '\0';
        count3 = count2 + 1;
        main_count = 0;

        for (int i = 0; i < 3; i++) {
            wordtype[main_count++] = temp_string[count3++];
        }
        wordtype[main_count] = '\0';
        if (!strcmp(wordtype, "nou")) {
            temp_type = WordType(0);
        } else if (!strcmp(wordtype, "ver")) {
            temp_type = WordType(1);
        } else if (!strcmp(wordtype, "adj")) {
            temp_type = WordType(2);
        } else {
            temp_type = WordType(3);
        }

        insertWord(text, meaning, temp_type, words, current_size);
        (*currentSize) = (*currentSize) + 1;
    }
    delete [] text; text = NULL;
    delete [] meaning; meaning = NULL;
    delete [] wordtype; wordtype = NULL;
    delete [] temp_string; temp_string = NULL;

    cout << endl << "The Import is complete! " << endl;
    ifs.close();

}


// write dictionary entries in the program to an external file
void writeExternalDictionary(const char file[], const Word words[], const int currentSize) {
    if (strlen(file) > MAX_FILENAME_LENGTH) {
        cout << "The file name is too long. Please try again.";
        return;
    }
    ofstream ofs;
    ofs.open(file);
    if (!ofs) {
        cerr << "Error: Can't open \"" << file << "\"\n"; return;
    }

    for (int i = 0; i < currentSize-1; i++) {
        for (int j = 0; words[i].text[j] != '\0'; j++) {
            ofs.put(words[i].text[j]);
        }
        ofs.put('\t');
        for (int j = 0; words[i].meaning[j] != '\0'; j++) {
            ofs.put(words[i].meaning[j]);
        }
        ofs.put('\t');
        switch (static_cast<int>(words[i].type)) {
        case 0:
            ofs.put('n'); ofs.put('o'); ofs.put('u'); ofs.put('n');
            break;
        case 1:
            ofs.put('v'); ofs.put('e'); ofs.put('r'); ofs.put('b');
            break;
        case 2:
            ofs.put('a'); ofs.put('d'); ofs.put('j'); ofs.put('e'); ofs.put('c');
            ofs.put('t'); ofs.put('i'); ofs.put('v'); ofs.put('e');
            break;
        case 3:
            ofs.put('a'); ofs.put('d'); ofs.put('v'); ofs.put('e'); ofs.put('r'); ofs.put('b');
            break;
        }
        ofs.put('\n');
    }

    for (int j = 0; words[currentSize-1].text[j] != '\0'; j++) {
            ofs.put(words[currentSize-1].text[j]);
        }
        ofs.put('\t');
        for (int j = 0; words[currentSize-1].meaning[j] != '\0'; j++) {
            ofs.put(words[currentSize-1].meaning[j]);
        }
        ofs.put('\t');
        switch (static_cast<int>(words[currentSize-1].type)) {
        case 0:
            ofs.put('n'); ofs.put('o'); ofs.put('u'); ofs.put('n');
            break;
        case 1:
            ofs.put('v'); ofs.put('e'); ofs.put('r'); ofs.put('b');
            break;
        case 2:
            ofs.put('a'); ofs.put('d'); ofs.put('j'); ofs.put('e'); ofs.put('c');
            ofs.put('t'); ofs.put('i'); ofs.put('v'); ofs.put('e');
            break;
        case 3:
            ofs.put('a'); ofs.put('d'); ofs.put('v'); ofs.put('e'); ofs.put('r'); ofs.put('b');
            break;
        }

    ofs.close();
}

// read a paragraph and store the words one by one uniquely in the newWords array
void readExternalFile(const char file[], char newWords[][MAX_TEXT_LENGTH], int* numOfNewWords) {
    // This part is for inputing the file.
    if (strlen(file) > MAX_FILENAME_LENGTH) {
        cout << "The file name is too long. Please try again.";
        return;
    }
    ifstream ifs;
    ifs.open(file);
    if (!ifs) {
        cerr << "Error: Can't open \"" << file << "\"\n"; return;
    }

    char* sentence = new char [MAX_LINE_LENGTH];

    do {
        ifs.getline(sentence, MAX_LINE_LENGTH, LINE_DELIM);

        int main_count = 0;

        while (sentence[main_count] != '\0') {
            if (!((sentence[main_count]>='A'&&sentence[main_count]<='Z')||(sentence[main_count]>='a'&&sentence[main_count]<='z'))){
                main_count++;
                continue;
            }
            bool flag = true;
            char* temp_string = new char [MAX_TEXT_LENGTH];
            int temp_count = 0;
            while (sentence[main_count] != ',' && sentence[main_count] != '.' && sentence[main_count] != ' ') {
                if (sentence[main_count] >= 'A' && sentence[main_count] <= 'Z') {
                    sentence[main_count] = sentence[main_count] - 'A' + 'a';
                }
                temp_string[temp_count++] = sentence[main_count++];
            }
            temp_string[temp_count] = '\0';
            main_count++;
            for (int i = 0; i < (*numOfNewWords); i++) {
                if (strcmp(newWords[i], temp_string) == 0) {
                    flag = false;
                    // cout << "The word: " << temp_string << " is repeated. False. " << endl;
                    break;
                }
            }
            if (flag) {
                strcpy(newWords[(*numOfNewWords)], temp_string);
                *numOfNewWords = (*numOfNewWords) + 1;
                // cout << "The word: " << temp_string << " is added. True. " << endl;
            }
            delete [] temp_string; temp_string = NULL;
        }
    } while (ifs.eof());

    cout << "File reading is complete. Total number of unique words: " << (*numOfNewWords) << endl;
    delete [] sentence; sentence = NULL;


}

// print information about the input paragraph
void printInfo(const Word words[], const int currentSize, const char newWords[][MAX_TEXT_LENGTH], const int numOfNewWords) {
    cout << "The list of unique words are: ";
    char** uncorrectWords = new char* [numOfNewWords];
    for (int i=0;i<numOfNewWords;i++){
        uncorrectWords[i] = new char [MAX_TEXT_LENGTH];
    }
    int main_count = 0;

    for (int i=0; i<numOfNewWords-1;i++){
        cout << newWords[i] << ", ";
    }
    cout << newWords[numOfNewWords-1]<<endl;


    for (int i = 0; i < numOfNewWords; i++) {
        bool flag = false;
        for (int j = 0; j < currentSize; j++) {
            if (strcmp(words[j].text, newWords[i]) == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            strcpy(uncorrectWords[main_count++],newWords[i]);
        }
    }

    if (main_count == 0) {
        cout << "No mistake is found. " << endl;
    } else {
        cout << "The following word(s) have some spelling mistakes which are to be corrected: " << endl;
        for (int i = 0; i < main_count; i++) {
            cout << uncorrectWords[i] << ", ";
        }
    }
    for (int i=0;i<numOfNewWords;i++){
        delete [] uncorrectWords[i]; uncorrectWords[i]=NULL;
    }
    delete [] uncorrectWords; uncorrectWords=NULL;
}
