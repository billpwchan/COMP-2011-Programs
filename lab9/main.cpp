#include <iostream>
#include "family.h"
using namespace std;
registry regis = {};

int main() {
	//initialization for regis
	regis.num = 0;

	//part1: build the family tree for Simpsons and implement the functions: searchPerson, createPerson, getMarried,addKid
	// build the node of family tree with given values
	cout << "Building the family tree with given values" << endl;
	person* m_ancestor1 = createPerson(female, "Mona", 50);
	person* f_ancestor1 = createPerson(male, "Abraham", 52);
	person* m_ancestor2 = createPerson(female, "Jackie", 50);
	person* f_ancestor2 = createPerson(male, "Clancy", 52);


	getMarried("Mona", "Abraham");
	getMarried("Jackie", "Clancy");
	addKid("Mona", "Abraham", "Herb", male, 30);
	addKid("Mona", "Abraham", "Homer", male, 32);
	addKid("Jackie", "Clancy", "Marge", female, 29);
	addKid("Jackie", "Clancy", "Patiy", female, 31);
	addKid("Jackie", "Clancy", "Selma", female, 33);
	getMarried("Homer", "Marge");
	addKid("Homer", "Marge", "Bart", male, 5);
	addKid("Homer", "Marge", "Lisa", female, 7);
	addKid("Homer", "Marge", "Maggie", male, 9);
	addKid("Homer", "Marge", "Maggie", male, 9);

	cout << "************Start the testing*************" << endl;
	//part2: implement the function of printing its relatives'name and delete the dynamic variables if no longer used
	cout << endl;
	cout << endl;
	cout << "Print the Lisa's parents, grandparents, uncles and aunts" << endl;
	printParents("Lisa");
	printGrandParents("Lisa");
	printUnclesAunts("Lisa");
	//Testing for the data incomplete cases
	printParents("Mona");
	printGrandParents("Mona");
	printUnclesAunts("Mona");


}


