#include <iostream>
using namespace std;

const int SIZE = 10;        //size of the maze

/* Part 1 */
bool solvable(int maze[], int start)
{
    // Add your code here
    if (start >= 10 || start < 0) {
        cout << "It is Dead end! " << endl;
        return false;
    }
    if (maze[start] < 0) {
        cout << "Now is at maze[" << start << "] = " << maze[start] << endl;
        cout << "You have moved to this position before" << endl ;
        return false;
    }
    if (start == 9) {
        cout << "Now is at maze[" << start << "] = " << maze[start] << endl;
        cout << "Solved!" << endl;
        return true;
    }

    int marker = maze[start];
    cout << "Now is at maze[" << start << "] = " << maze[start] << endl;
    cout << "Go right " << marker << " step" << endl;
    maze[start] = -1;
    if (solvable(maze, start + marker)) {
        return true;
    } else {
        cout << "Go left " << marker << " step" << endl;
        if (solvable(maze, start - marker)) {
            return true;
        } else {
            maze[start] = marker;
        }
    }

    return false;
}

int main()
{
    int x[SIZE], n;

    cout << "Part 1\n" << "Please enter the puzzle: ";
    for (int i = 0; i < SIZE; i++)
        cin >> x[i];

    if (solvable(x, 0))
        cout << "The puzzle is solvable." << endl;
    else
        cout << "The puzzle cannot be solved." << endl;

    return 0;
}