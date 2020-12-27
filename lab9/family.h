#ifndef FAMILY_H_
#define FAMILY_H_
using namespace std;

enum SEX {male, female};
const int MAX_NAME_LENGTH = 20;
const int MAX_REGISTRY_NUM = 100;
const int MAX_KID_NUM = 3;

struct person {
    SEX sex;
    char name[MAX_NAME_LENGTH];
    int age;
    person* spouse;  // NULL if single or widowed
    person* mother;
    person* father;
    person* kid[MAX_KID_NUM]; // NULL if no kid
};

//collection of all persons in family tree, help to search a person with given name quickly
struct registry {
    int num;
    person* p[MAX_REGISTRY_NUM];
};
extern registry regis;

/**
 *a function create the person struct and return its pointer
 *a new entry should also be added to regis.p
 */
person* createPerson( const SEX sex, const char name[MAX_NAME_LENGTH], int age);

// a helper function for all print tasks: given name, search the personList to retrieve the pointer.
person* searchPerson( const char name[MAX_NAME_LENGTH]);
// setup the link to spouse
void getMarried(const char husband_name[MAX_NAME_LENGTH], const char wife_name[MAX_NAME_LENGTH]);

/**
 * create  a person with age 1, then setup the link to parents. Parents node should set link to this baby too.
 * a new entry should also be added to regis.p
 */
void addKid(const char father_name[MAX_NAME_LENGTH], const char mother_name[MAX_NAME_LENGTH],
            const char baby_name[MAX_NAME_LENGTH], SEX sex, int age);
/**
 *print his/her parents' name,
 *if the father/mother pointer of the person with the given name is NULL,print "the data is incomplete" instead.
 */
void printParents(const char name[MAX_NAME_LENGTH]);
/**
 *print four names including grandparent both side
 *if any father/mother pointer of the person or peron's parents is NULL,print "the data is incomplete" instead
 */
void printGrandParents(const char name[MAX_NAME_LENGTH]);
/**
 *if any, print uncles/aunts' name, otherwise print "no uncle and aunt"
 *if any father/mother pointer of the person or peron's parents is NULL,print "the data is incomplete" instead
 */
void printUnclesAunts(const char name[MAX_NAME_LENGTH]);




#endif /* FAMILY_H_ */
