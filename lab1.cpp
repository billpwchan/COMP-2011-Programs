#include <iostream>
using namespace std;


int month, day;
bool flag = true;

void check_month();
void check_day();


int main(void) {

	check_month();
	check_day();
	cout << "The input is valid" << endl;

	return 0;
}

void check_month() {
	cout << "Please enter the month (1-12): ";
	cin >> month;


	while (month > 12 || month < 1) {
		cout << "The input month is invalid." << endl;
		cout << "Please enter the month (1-12):";
		cin >> month;
	}
}

void check_day(){
		cout << "Please enter the day: ";
	cin >> day;
	while (flag) {
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:

			if (day > 31 || day < 1) {
				cout << "The input day is incorrect. There are only 31 days in this month." << endl;
				check_month();
			} else {
				flag = false;
			}
			break;

		case 2:
			if (day > 29 || day < 1) {
				cout << "The input day is incorrect. There are only 29 days in this month." << endl;
				check_month();
			} else {
				flag = false;
			}
			break;

		case 4:
		case 6:
		case 9:
		case 11:

			if (day > 30 || day < 1) {
				cout << "The input day is incorrect. There are only 30 days in this month." << endl;
				check_month();

			} else {
				flag = false;
			}
			break;


		}
		if (flag ==  true) {
			cout << "Please enter the day: ";
			cin >> day;
		}
	}
}

