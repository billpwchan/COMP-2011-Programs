#include <iostream>     /* File: distance-fcn.cpp */
#include <cmath>	    // Math library info
using namespace std;	

/* To find the Euclidean distance between 2 points */
int distance(int x1, int y1, int x2, int y2)
{
    int x_diff = x1 - x2;
    int y_diff = y1 - y2;
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

int main()   /* To find the length of the sides of a triangle */
{
    int xA, yA, xB, yB, xC, yC; 
    cout << "Enter the co-ordinates of point A: "; cin >> xA >> yA;
    cout << "Enter the co-ordinates of point B: "; cin >> xB >> yB;
    cout << "Enter the co-ordinates of point C: "; cin >> xC >> yC;

    cout << " AB = " << distance(xA, yA, xB, yB) << endl;
    cout << " BC = " << distance(xB, yB, xC, yC) << endl;
    cout << " CA = " << distance(xC, yC, xA, yA) << endl;
    return 0;
}
