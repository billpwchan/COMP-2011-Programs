#include <iostream>     /* File: student-record.h */
using namespace std;
const int MAX_NAME_LEN = 32;

class student_record
{
  private:
    char name[MAX_NAME_LEN];
    unsigned int id;

  public:
    // ACCESSOR member functions: const => won't modify data members
    const char* get_name() const { return name; }
    unsigned int get_id() const { return id; }
    void print() const
    { cout << "Name:\t" << name << "\nID:\t" << id << endl; }

    // MUTATOR member functions
    void set(const char* my_name, unsigned int my_id)
    { strcpy(name, my_name); id = my_id; }
    void copy(const student_record& sr) { set(sr.name, sr.id); }
};
