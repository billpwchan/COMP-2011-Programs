#include "student-record.h" /* File: student-record-test.cpp */

int main()	
{
    student_record adam, brian; // Create 2 static student_record objects

    adam.set("Adam", 12345);    // Put values to their data members
    brian.set("Brian", 34567);

    cout << adam.get_name() << endl; // Get and print some data member
    adam.copy(brian);           // Adam want to fake Brian's identity
    adam.print();

    return 0; 
    // Adam and Brian are static object, which will be destroyed
    // at the end of the function --- main( ) here --- call.
}   /* To compile: g++ student-record-test.cpp */
