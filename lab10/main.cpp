#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
	Matrix **m = new Matrix*[2];
	m[0] = createMatrix("/Users/billpwchan/Desktop/m1.txt");
	m[1] = createMatrix("/Users/billpwchan/Desktop/m2.txt");

	int option;

	do {
		// Menu
		cout << "===========================================" << endl;
		cout << "We have the following 2 matrix: " << endl;
		cout << "===========================================" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "matrix " << i + 1 << ": " << endl;
			printMatrix(m[i]);
		}
		cout << "===========================================" << endl;
		cout << "(1) Add two matrix" << endl;
		cout << "(2) Multiply two matrix" << endl;
		cout << "(3) Add row to a matrix" << endl;
		cout << "(4) Delete row from a matrix" << endl;
		cout << "(5) Quit" << endl << endl;
		cout << "Which operation you want to perform: ";
		cin >> option;

		Matrix *m3 = NULL;
		switch (option) {
		int x, y;
	case 1:
		m3 = matrixAddition(m[0], m[1]);
		if (m3 != NULL) {
			cout << "The added matrix is: " << endl;
			printMatrix(m3);
//			deleteMatrix(m3);
		}
		break;
	case 2:
		m3 = matrixMultiplication(m[0], m[1]);
		if (m3 != NULL) {
			cout << "The multiplied matrix is: " << endl;
			printMatrix(m3);
//			deleteMatrix(m3);
		}
		break;
	case 3:
		cout << "Which matrix do you want to add a row: ";
		cin >> x;
		addRow(m[x - 1]);
		cout << "matrix " << x << " now becomes:" << endl;
		printMatrix(m[x - 1]);
		break;
	case 4:
		cout << "Which matrix you want to delete a row: ";
		cin >> x;
		cout << "Which row do you want to delete: ";
		cin >> y;
		deleteRow(m[x - 1], y);
		cout << "matrix " << x << " now becomes:" << endl;
		printMatrix(m[x - 1]);
		break;
	default:
		break;
		}

	} while (option != 5);

	for (int i = 0; i < 2; i++) {
//		deleteMatrix(m[i]);
		m[i] = NULL;
	}
	delete[] m;
	m = NULL;
	cout << "All matrix are deleted." << endl;

    
    
    int height = 0;
    cout << "Enter the height of pyramid: ";
    cin >> height;
    cout << "A pyramid of height " << height << " is created: " << endl;
    Pyramid* p = createPyramid(height);
    printPyramid(p);
    deletePyramid(p);
    
	return 0;
}
