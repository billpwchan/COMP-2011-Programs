#include "struct_definition.h"



int main(void) {
	string name, address, phone_num;
	cout << "Please input the name: ";
	cin >> name;
	cout << "Please input the address: ";
	cin >> address;
	cout << "Please input the phone_num: ";
	cin >> phone_num;
	Personal_info person = {name, address, phone_num};

	cout << person.user_name << endl;
	return 0;
}