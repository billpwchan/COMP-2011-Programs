#include <iostream>     /* File: read-str.cpp */
using namespace std;	

int main()	
{
    const int MAX_LINE_LEN = 1000;
    char s[MAX_LINE_LEN+1];

    // Read until the newline character (default)
    cin.getline(s, MAX_LINE_LEN+1, '\n'); 
    cout << s << endl;
    
    // Read until the character 'W'
    cin.getline(s, sizeof(s), 'W'); 
    cout << s << endl;

    return 0;
}
