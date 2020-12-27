#include <iostream>
#include <cmath>
using namespace std;

void print_message(void);
void print_float_result(float num1, bool x, char op, float num2, bool y, float result);
void reset(bool &x, bool &y);
void input_float(float &x, float &y);
void input_int(int &x, int &y);
float float_multiplication(float x, float y);
float float_division(float x, float y);
int int_multiplication(int x, int y );
int int_division(int x, int y);
double square_root(double S);
double square_root_operation(double xn, double S);


int main(void) {
	float float_x, float_y, float_result;
	int choice, int_x, int_y, int_result;
	double double_x, double_result;
	bool x_flag = true, y_flag = true;
	print_message();
	cin >> choice;

	do {
		// This part is to determine whether the input is valid.
		while (choice > 5 || choice < 0) {
			cout << "Your choice is invalid, please enter again. " << endl;
			cin >> choice;
		}

		if (choice == 0) {break;}

		// This part is to determine which choice that user chose.
		switch (choice) {

		case 1: {
			input_float(float_x, float_y);
			if (float_x < 0) {x_flag = false;}
			if (float_y < 0) {y_flag = false;}
			float_result = float_multiplication(float_x, float_y);
			print_float_result(float_x, x_flag, '*', float_y, y_flag, float_result);

			reset(x_flag, y_flag);
		} break;


		case 2: {
			input_float(float_x, float_y);
			while (float_y == 0) {
				cout << "The divisor cannot be zero! " << endl;
				cout << "Please input y: " << endl;
				cin >> float_y;
			}
			if (float_x < 0) {x_flag = false;}
			if (float_y < 0) {y_flag = false;}
			float_result = float_division(float_x, float_y);
			print_float_result(float_x, x_flag, '/', float_y, y_flag, float_result);

			reset(x_flag, y_flag);

		} break;


		case 3: {
			cout << "Please input x: " << endl;
			cin >> int_x;
			while (int_x < 0) {
				cout << "Negative number is rejected! " << endl;
				cout << "Please input x: " << endl;
				cin >> int_x;
			}
			cout << "Please input y: " << endl;
			cin >> int_y;
			while (int_y < 0) {
				cout << "Negative number is rejected! " << endl;
				cout << "Please input y: " << endl;
				cin >> int_y;
			}
			int_result = int_multiplication(int_x, int_y);
			cout << int_x << ' ' << "mul " << int_y << " = " << int_result << endl;
		} break;


		case 4: {
			cout << "Please input x: " << endl;
			cin >> int_x;
			while (int_x < 0) {
				cout << "Negative number is rejected! " << endl;
				cout << "Please input x: " << endl;
				cin >> int_x;
			}
			cout << "Please input y: " << endl;
			cin >> int_y;
			while (int_y <= 0) {
				cout << "Negative number and zero is rejected! " << endl;
				cout << "Please input y: " << endl;
				cin >> int_y;
			}
			int_result = int_division(int_x, int_y);
			cout << int_x << ' ' << "div " << int_y << " = " << int_result << endl;
		} break;

		case 5: {
			cout << "Please input x: " << endl;
			cin >> double_x;
			while (double_x < 0) {
				cout << "Negative number is rejected! " << endl;
				cout << "Please input x: " << endl;
				cin >> double_x;
			}
			double_result = square_root(double_x);
			cout << double_x << "'s square root is " << double_result << endl;

		} break;

		}

		cout << endl;
		print_message();
		cin >> choice;
	} while (choice != 0);

	return 0;
}

void print_message(void) {
	cout << "Welcome to the simulated calculator" << endl
	     << "1. Perform float multiplication" << endl
	     << "2. Perform float division" << endl
	     << "3. Perform integer multiplication" << endl
	     << "4. Perform integer division" << endl
	     << "5. Perform taking square root operation" << endl
	     << "0. Quit" << endl
	     << "Please enter your choice [0-5]: " << endl;
}

void print_float_result(float num1, bool x, char op, float num2, bool y, float result) {
	if (x) {
		cout << num1 << ' ';
	} else {
		cout << '(' << num1 << ") ";
	}
	cout << op << ' ';

	if (y) {
		cout << num2 << ' ';
	} else {
		cout << '(' << num2 << ") ";
	}
	cout << " = " << result << endl;
}

void reset(bool &x, bool &y) {
	x = true;
	y = true;
}

void input_float(float &x, float &y) {
	cout << "Please input x: " << endl;
	cin >> x;
	cout << "Please input y: " << endl;
	cin >> y;
}

void input_int(int &x, int &y) {
	cout << "Please input x: " << endl;
	cin >> x;
	cout << "Please input y: " << endl;
	cin >> y;
}

float float_multiplication(float x, float y) {
	return x * y;
}

float float_division(float x, float y ) {
	return x / y;
}

int int_multiplication(int x, int y) {
	int result = x;
	for (int i = 1; i < y; i++) {result += x;}
	return result;
}

int int_division(int x, int y) {
	int result = x, count = 0;
	while (result > 0 && result > y) {
		result -= y;
		count++;
	}
	return count;
}

double square_root(double S) {
	int temp = 0;
	double result;
	while ((temp * temp) < S) {
		temp++;
	}
	result = temp * temp * 1.0;
	// cout << result<<endl;
	do {
		result = square_root_operation(result, S);
		// cout << "Test cycle. "<<result<<endl;
	} while (abs(result * result - S) > 0.0000001);
	return result;

}

double square_root_operation(double xn, double S) {
	return 1.0 / 2 * (xn + S / xn);
}