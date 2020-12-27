#include <iostream>     /* File: one-rat.cpp */
using namespace std;

int main() 
{
    cout << "Size of a RAT: " << endl;
    int size;
    cin >> size;

    for (int width = 1; width <= size; width++) 
    {
        // Draw one row of a RAT
        for (int j = 0; j < width ; j++)
            cout << '*';

        cout << endl;   
    }

    return 0;
}


