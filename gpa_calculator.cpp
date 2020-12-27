#include <iostream>
using namespace std;

int return_number(char grade);

int main(void) {
	int credit, total_credits = 0, score;
	char grade;
	double result = 0;
	cout << "No. of credits of your course (0 to stop):  ";
	cin >> credit;

	while (credit != 0 ) {

		try {
			cout << "Please input the letter grade (A, B, C, D, E):  ";
			cin >> grade;
			if (grade != 'A' || grade != 'a' || grade != 'B' || grade != 'b' || grade != 'C' || grade != 'c' || grade != 'D' || grade != 'd' || grade != 'E' || grade != 'e') {
				throw "Invalid Input of letter grade. ";
			}
		} catch (const char* msg) {
			cout << msg << endl;
		}

		score = return_number(grade);
		result += credit * score;
		total_credits += credit;

		cout << "No. of credits of your course (0 to stop):  ";
		cin >> credit;
	}

	cout << "The total credits are:  " << total_credits << endl
	     << "The result GPA is: " << result / total_credits << endl;



	return 0;
}

int return_number(char grade) {
	switch (grade) {
	case 'a':
	case 'A':
		return 4;
		break;
	case 'b':
	case 'B':
		return 3;
		break;
	case 'c':
	case 'C':
		return 2;
		break;
	case 'd':
	case 'D':
		return 1;
		break;
	case 'e':
	case 'E':
		return 0;
		break;
	// default:
	// 	cout << "Invalid input. " << endl;
	// 	return (-1);
	// 	Utilize exception handling system to ensure the correctness of function's input.

	}


}