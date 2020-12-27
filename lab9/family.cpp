#include <iostream>
#include "family.h"
using namespace std;


person* createPerson(const SEX sex, const char name[MAX_NAME_LENGTH], int age)
{
	person* new_person = new person;
	new_person->sex = sex;
	for (int i = 0; name[i] != '\0'; i++) {
		new_person->name[i] = name[i];
	}
	new_person->age = age;
	new_person->spouse = NULL;
	new_person->mother = NULL;
	new_person->father = NULL;
	for (int i = 0; i < MAX_KID_NUM; i++) {
		new_person->kid[i] = NULL;
	}
	regis.p[regis.num++] = new_person;

	return new_person;
}

person* searchPerson(const char name[MAX_NAME_LENGTH])
{
	bool search_true(const char*, const char*);
	for (int i = 0; i < regis.num; i++) {
		if (search_true(regis.p[i]->name, name)) {
			return regis.p[i];
		}
	}
	return NULL;
}

bool search_true(const char* name1, const char* name2) {
	int count1 = 0; int count2 = 0;
	while (name1[count1] != '\0' && name2[count2] != '\0') {
		if (name1[count1] != name2[count2]) {
			return false;
		}
		count1++; count2++;
	}
	if ((name1[count1] == '\0' && name2[count2] != '\0') || (name1[count1] != '\0' && name2[count2] != '\0')) {
		return false;
	}
	return true;
}

void getMarried(const char husband_name[MAX_NAME_LENGTH], const char wife_name[MAX_NAME_LENGTH])
{
	person* husband = searchPerson(husband_name);
	person* wife = searchPerson(wife_name);
	if (husband == NULL || wife == NULL) {
		cout << "Fail. " << endl;
		return;
	}
	husband->spouse = wife;
	wife->spouse = husband;
	cout << "Congradulations! " << husband->name << " " << wife->name << " are married" << endl;
}

void addKid(const char father_name[MAX_NAME_LENGTH], const char mother_name[MAX_NAME_LENGTH],
            const char kid_name[MAX_NAME_LENGTH], const SEX sex, int age)
{
	person* father = searchPerson(father_name);
	person* mother = searchPerson(mother_name);

	if (father == NULL || mother == NULL) {
		cout << "Failed, can not be added." << endl;
		return;
	}
	if (searchPerson(kid_name) != NULL) {
		cout << "Add " << kid_name << " second times: " << endl;
		cout << "Failed, this kid was added before." << endl;
		return;
	}
	person* kid = createPerson(sex, kid_name, age);
	int father_kidcount = 0; int mother_kidcount = 0;
	while (father->kid[father_kidcount] != NULL) {
		father_kidcount++;
	}
	while (mother->kid[mother_kidcount] != NULL) {
		mother_kidcount++;
	}
	father->kid[father_kidcount] = kid;
	mother->kid[mother_kidcount] = kid;
	kid->father = father;
	kid->mother = mother;
	regis.p[regis.num++] = kid;
	cout << "The kid " << kid->name << " is added" << endl;



}

void printParents(const char name[MAX_NAME_LENGTH])
{
	person* kid = searchPerson(name);
	if (kid == NULL) {
		cout << "The data is incomplete. " << endl;
		return;
	}
	if (kid->father == NULL || kid->mother == NULL) {
		cout << "The data is incomplete. " << endl;
		return;
	}
	cout << "Father: " << kid->father->name << endl;
	cout << "Mother: " << kid->mother->name << endl;


}

void printGrandParents(const char name[MAX_NAME_LENGTH])
{
	person* kid = searchPerson(name);
	if (kid == NULL) {
		cout << "The data is incomplete. " << endl;
		return;
	}
	if (kid->father == NULL || kid->mother == NULL) {
		cout << "The data is incomplete. " << endl;
		return;
	}
	if (kid->father->father == NULL || kid->father->mother == NULL || kid->mother->father == NULL || kid->mother->father == NULL) {
		cout << "The data is incomplete. " << endl;
		return;
	}
	cout << "GrandMother: " << kid->father->mother->name << " and " << kid->mother->mother->name << endl;
	cout << "GrandFather: " << kid->father->father->name << " and " << kid->mother->father->name << endl;
}

void printUnclesAunts(const char name[MAX_NAME_LENGTH])
{
	person* kid = searchPerson(name);
	if (kid == NULL) {
		cout << "The data is incomplete. " << endl;
		return;
	}
	if (kid->father == NULL || kid->mother == NULL) {
		cout << "The data is incomplete. " << endl;
		return;
	}
	if (kid->father->father == NULL || kid->father->mother == NULL || kid->mother->father == NULL || kid->mother->father == NULL) {
		cout << "The data is incomplete. " << endl;
		return;
	}
	int father_kidcount = 0; int mother_kidcount = 0;
	while (kid->father->father->kid[father_kidcount] != NULL && father_kidcount < 3) {
		father_kidcount++;
	}
	while (kid->mother->mother->kid[mother_kidcount] != NULL && mother_kidcount < 3) {
		mother_kidcount++;
	}
	cout << "Uncle and aunts: " << endl;
	for (int i = 0; i < father_kidcount; i++) {
		if (!search_true(kid->father->father->kid[i]->name, kid->father->name)) {
			cout << kid->father->father->kid[i]->name << endl;
		}
	}
	for (int i = 0; i < mother_kidcount; i++) {
		if (!search_true(kid->mother->mother->kid[i]->name, kid->mother->name)) {
			cout << kid->mother->mother->kid[i]->name << endl;
		}
	}



}


