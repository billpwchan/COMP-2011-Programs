#include "mystring.h"   /* File: mystring_accessors.cpp */

int mystring::length() const
{
    int length = 0;
    for (const ll_cnode* p = head; p != NULL; p = p->next)
        length++;

    return length;
}


void mystring::print() const
{
    for (const ll_cnode* p = head; p != NULL; p = p->next)
        cout << p->data;

    cout << endl;
}
