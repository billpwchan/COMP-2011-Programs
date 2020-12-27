#include <iostream>
using namespace std;

void print_separation();

int main() {
	int size;
	cout << "Size of a RAT: " << endl;
	cin >> size;

	cout << "A simple RAT. ";

	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "*" << " ";
		}
		cout << endl;
	}

	// Separation;
	cout <<endl;
	print_separation();


	cout << "A upside-down RAT. " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			cout << "*" << " ";
		}
		cout << endl;
	}

	return 0;
}

void print_separation() {
	for (int i = 0; i < 20; i++) {
		cout << "*";
	}
	cout << endl;
}