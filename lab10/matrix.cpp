#include "matrix.h"

void printMatrix(const Matrix* m){
	if (m == NULL){
		cout << "The matrix does not exist anymore" << endl;
		return;
	}
	// Print the matrix element
	for (int i = 0 ; i < m->row ; i++){
		for (int j = 0 ; j < m->col ; j++){
			cout << m->data[i][j] << ' ';
		}
		cout << endl;
	}
}

Matrix* createMatrix(const char file[]){
    ifstream fin(file);
    if (!fin){
        cerr << "Error: Cannot open the file" << endl;
        return NULL;
    }

    //TODO 1: Create a new matrix by reading the file
    //The numbers in the first row represent the dimension (row and column) of the matrix
	//The numbers starting from the second row are the matrix element
	int row; fin >> row;
	cout << row<<endl;
	int column; fin >> column;
	cout << column<<endl;
	Matrix* new_matrix=new Matrix;
	new_matrix->row=row;
	new_matrix->col=column;
    int** ary = new int*[row];
    for (int i=0;i<row;i++){
        ary[i]=new int[column];
    }


	for (int i=0;i<row;i++){
		for (int j=0; j<column;j++){
            int number; fin>>number;
            ary[i][j]=number;
		}
	}
    new_matrix->data=ary;
	fin.close();

    return new_matrix;
}

Matrix* createMatrix(int dim){
    Matrix* new_matrix=new Matrix;
    new_matrix->row=dim;
    new_matrix->col=dim;
    int** ary = new int*[dim];
    for (int i=0;i<dim;i++){
        ary[i]=new int[dim];
    }
    
    
    for (int i=0;i<dim;i++){
        for (int j=0; j<dim;j++){
            ary[i][j]=dim;
        }
    }
    new_matrix->data=ary;
    return new_matrix;
}


Matrix* matrixAddition(const Matrix* m1, const Matrix* m2){
	//TODO 2: Create a new matrix by adding two matrix
    if (m1->row!=m2->row||m1->col!=m2->col){
        return NULL;
    }
    Matrix* new_matrix=new Matrix;
    new_matrix->row=m1->row;
    new_matrix->col=m1->col;
    int** ary = new int*[new_matrix->row];
    for (int i=0; i<new_matrix->row;i++){
        ary[i]=new int[new_matrix->col];
    }
    for (int i=0; i<new_matrix->row; i++){
        for (int j=0; j<new_matrix->col; j++){
            ary[i][j]=m1->data[i][j]+m2->data[i][j];
        }
    }
    new_matrix->data=ary;
    return new_matrix;
}

int calculate_node(const Matrix* m1, const Matrix* m2, int row, int col){
    int sum=0;
    for (int i=0; i<m1->col; i++){
            sum+=m1->data[row][i]*m2->data[i][col];
    }
    return sum;
}

Matrix* matrixMultiplication(const Matrix* m1, const Matrix* m2){
	//TODO 3: create a new matrix by multiply two matrix
    if (m1->col!=m2->row){
        cout << "Matrix dimension does not match! "<<endl;
        return NULL;
    }
    Matrix* new_matrix=new Matrix;
    new_matrix->row=m1->row;
    new_matrix->col=m2->col;
    int** ary = new int*[new_matrix->row];
    for (int i=0; i<new_matrix->row;i++){
        ary[i]=new int[new_matrix->col];
    }
    for (int i=0; i<new_matrix->row;i++){
        for (int j=0; j<new_matrix->col;j++){
            ary[i][j]=calculate_node(m1, m2, i, j);
        }
    }
    new_matrix->data=ary;
    return new_matrix;
}


void addRow(Matrix *m){
	//TODO 4: Add a row at the last row of the matrix
    m->row=m->row+1;
    int* temp_string = new int[m->col];
    int** ary = new int*[m->row];
    for (int i=0; i<m->row;i++){
        ary[i]=new int[m->col];
    }
    cout << "Input the row: ";
    for (int i=0;i<m->col;i++){
        cin >> temp_string[i];
    }
    for (int i=0; i<m->row-1;i++){
        for (int j=0;j<m->col;j++){
            ary[i][j]=m->data[i][j];
        }
    }
    for (int i=0;i<m->col;i++){
        ary[m->row-1][i]=temp_string[i];
    }
    m->data=ary;
    
}

void deleteRow(Matrix *m, int r){
	//TODO 5: Delete the r-th row of the matrix
    //Assume r = 2; 1357; 2468, 3579,46810
    int** ary = new int*[m->row-1];
    for (int i=0; i<m->row-1;i++){
        ary[i]=new int[m->col];
    }
//    for (int i=0; i<r-1;i++){
//        for (int j=0;j<m->col;j++){
//            ary[i][j]=m->data[i][j];
//        }
//    }
//    for (int i=r;i<m->row;i++){
//        for (int j=0;j<m->col;j++){
//            ary[i-1][j]=m->data[i][j];
//        }
//    }
    int count=0;
    for (int i=0;i<m->row;i++, count++){
        for (int j=0;j<m->col;j++){
            if (i==(r-1)){
                count--;
                break;
            }else{
                ary[count][j]=m->data[i][j];
            }
        }
    }
    m->data=ary;
    m->row=m->row-1;
}


void deleteMatrix(Matrix *m){
	while (m->row > 0){
		deleteRow(m, 1);
	}
	delete[] m->data;
	m->data = NULL;
	delete m;
}

Pyramid* createPyramid(int number){
    Pyramid* new_pyramid= new Pyramid;
    Matrix* arr_matrix=new Matrix[number];
    new_pyramid->dimension=number;
    for (int i=0;i<number;i++){
        arr_matrix[i]=*createMatrix(i+1);
    }
    new_pyramid->arr_matrix=arr_matrix;
    return new_pyramid;
}
void printPyramid(const Pyramid* new_pyramid){
    for (int i=0;i<new_pyramid->dimension;i++){
        printMatrix(&new_pyramid->arr_matrix[i]);
    }
}
void deletePyramid(Pyramid* old_pyramid){
    
}


