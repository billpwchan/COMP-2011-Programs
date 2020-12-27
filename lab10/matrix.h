#include <iostream>
#include <fstream>
using namespace std;

// Matrix structure
struct Matrix{
	int row;
	int col;
	int **data;
};

struct Pyramid{
    int dimension;
    Matrix* arr_matrix;
};

// Matrix functions

// Print the matrix
void printMatrix(const Matrix* m);

// Create a new matrix by reading the file
Matrix* createMatrix(const char file[]);

// Return the addition of 2 matrix
Matrix* matrixAddition(const Matrix* m1, const Matrix* m2);

// Return the multiplication of 2 matrix
Matrix* matrixMultiplication(const Matrix* m1, const Matrix* m2);

// Add a row at the last row of the matrix
void addRow(Matrix *m);

// Delete the r-th in the matrix
void deleteRow(Matrix *m, int r);

// Delete the whole matrix
void deleteMatrix(Matrix *m);

Pyramid* createPyramid(int);
void printPyramid(const Pyramid*);
void deletePyramid(Pyramid*);
