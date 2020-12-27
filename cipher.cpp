#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;



enum Operation {
	DECRYPT, ENCRYPT
};

void endecrypt(const char input[], const char key[], char output[], Operation opt);
char shift_encrypt(char original_letter, char key_letter);
char shift_decrypt(char original_letter, char key_letter);
// TODO 1: Shift a letter
// Add your function here

// TODO 2: En/Decryption
// Add your function here. You should use endecrypt as the function name

int main() {
	// set up the array
	const int SIZE = 101; //the size of the input message is at most 100 characters

	char input[SIZE] = "";
	char key[SIZE] = "";
	char output[SIZE] = "";

	int option = 0;
	do {
		//initialize the three arrays
		input[0] = '\0';
		key[0] = '\0';
		output[0] = '\0';
		cout << "This is a Vigenere cipher machine." << endl;
		cout << "You can input at most 100 characters." << endl;
		cout << "1. Encrypt a plaintext" << endl;
		cout << "2. Decrypt a ciphertext" << endl;
		cout << "3. Exit" << endl;
		do {
			cout << "Please select an option (1 - 3): ";
			cin >> option;
			// To skip the enter key
			cin.ignore();

		} while (option < 1 || option > 3);

		if (option == 1) {
			cout << "Your plaintext is: ";
			// get the input including the whitespace but terminate when it is over the size or reach the newline character
			cin.getline(input, SIZE, '\n');
			cout << "The keyword is: ";
			cin >> key;
			endecrypt(input, key, output, ENCRYPT);
			cout << "The ciphertext is: " << output << endl << endl;
		} else if (option == 2) {
			cout << "Your ciphertext is: ";
			cin.getline(input, SIZE, '\n');
			cout << "The keyword is: ";
			cin >> key;
			endecrypt(input, key, output, DECRYPT);
			cout << "The plaintext is: " << output << endl << endl;
		}
	} while (option != 3);

	return 0;
}

void endecrypt(const char input[], const char key[], char output[], Operation opt) {
	int i = 0, j = 0;

	do {
		if (j == strlen(key))
			j = 0;

		while (input[i] == ' ') {
			output[i] = ' ';
			i++;
		}
		if (static_cast<int>(opt) == 1) {
			output[i] = shift_encrypt(input[i], key[j]);
		} else {
			output[i] = shift_decrypt(input[i], key[j]);
		}
		i++;
		j++;
	} while (input[i] != '\0');
	output[i] = '\0';


}


char shift_encrypt(char original_letter, char key_letter) {
	int int_letter;
	if ((original_letter >= 'A' && original_letter <= 'Z') || (original_letter >= 'a' && original_letter <= 'z')) {
		if (key_letter >= 'A' && key_letter <= 'Z') {
			int_letter = static_cast<int>(original_letter) + static_cast<int>(abs(key_letter - 'A'));
			cout << int_letter << endl;
		} else {
			int_letter = static_cast<int>(original_letter) + static_cast<int>(abs(key_letter - 'a'));
			cout << int_letter << endl;
		}

		// cout << "Original letter "<< original_letter<<endl<<"New Letter "<<new_letter<<endl;

		if ((original_letter >= 'A' && original_letter <= 'Z') && int_letter > 90)
		{	int_letter = static_cast<int>('A') + abs(int_letter - 90 - 1);
		}
		if ((original_letter >= 'a' && original_letter <= 'z') && int_letter > 122)
		{	int_letter = static_cast<int>('a') + abs(int_letter - 122 - 1);
		}
		return static_cast<char>(int_letter);
	} else {
		return '@';
	}
}

char shift_decrypt(char original_letter, char key_letter) {
	int int_letter;
	if ((original_letter >= 'A' && original_letter <= 'Z') || (original_letter >= 'a' && original_letter <= 'z')) {
		if (key_letter >= 'A' && key_letter <= 'Z') {
			int_letter = static_cast<int>(original_letter) - static_cast<int>(abs(key_letter - 'A'));
			cout << int_letter << endl;
		} else {
			int_letter = static_cast<int>(original_letter) - static_cast<int>(abs(key_letter - 'a'));
			cout << int_letter << endl;
		}

		// cout << "Original letter "<< original_letter<<endl<<"New Letter "<<new_letter<<endl;

		if ((original_letter >= 'A' && original_letter <= 'Z') && int_letter < 65)
		{	int_letter = static_cast<int>('Z') - abs(int_letter - 65 +1);
		}
		if ((original_letter >= 'a' && original_letter <= 'z') && int_letter <97)
		{	int_letter = static_cast<int>('z') - abs(int_letter - 97 +1);
		}
		return static_cast<char>(int_letter);
	} else {
		return '@';
	}
}
