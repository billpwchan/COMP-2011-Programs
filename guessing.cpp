#include <iostream>
#include <stdlib.h>
#include <time.h> //When generating random number, we need assistance from time.h library.
#include <cstdlib> ///usr/include/c++/4.2.1
using namespace std;

int main() {
	bool flag = true;

	srand(time(0));
	int result_number = rand() % 100 + 1, guess_number, lower = 1, upper = 100;
	char check;
	cout << result_number << endl;

	while (true) {

		while (flag) {
			cout << "Please input a number: " << endl;
			cin >> guess_number;
			// Check if the guess_number is within the given range
			while (guess_number <= lower || guess_number >= upper) {
				cerr << "Out of range. Please try again. " << endl;
				cin >> guess_number;
				lower = guess_number;
			}

			if (guess_number > result_number) {
				cout << "It's smaller than " << guess_number << endl;
				upper = guess_number;
			}
			else {
				if (guess_number < result_number) {
					cout << "It's bigger than " << guess_number << endl;
				} else {
					flag = false;
					cout << "Correct. \n";
					break;
				}
			}
		}

		cout << "Do you want to continue? (y/n)" << endl;
		cin >> check;

		if (check == 'n') {
			break;
		}
		flag = true;
	}
	return 0;
}