#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int** formMatrix(int n, int m);
void printMatrix(int** matrix, int n, int m);
void fillMatrix(int** matrix, int n, int m);
void deleteMatrix(int** matrix, int n, int m);
void changeRowColumn(int** matrix, int n, int m, int k); 

int main() {
	srand(time(NULL));
	int size1 = 5;
	int index = 2;
	int** matrix1 = formMatrix(5, 5);
	fillMatrix(matrix1, size1, size1);
	cout << "Initial matrix : " << endl;
	printMatrix(matrix1, size1, size1);
	changeRowColumn(matrix1, size1, size1, index);
	cout << "Matrix after change " << index + 1 << "row and column" << endl;
	printMatrix(matrix1, size1, size1);
	deleteMatrix(matrix1, size1, size1);
	return 0;
}

int** formMatrix(int n, int m)
{
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	return arr;
}

void printMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
}

void fillMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = rand() % 101;
		}
	}
}

void deleteMatrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++) {
		delete matrix[i];
	}
	delete matrix;
}

void changeRowColumn(int** matrix, int n, int m, int k)
{
	for (int i = 0; i < n; i++) {
		int tmp = matrix[k][i];
		matrix[k][i] = matrix[i][k];
		matrix[i][k] = tmp;
	}
}
/*
void changeRowColumn(int** matrix, int n, int m, int k)
{
	for (int i = 0; i < n; i++) {
		if (i != k) {}
		int tmp = matrix[k][i];
		matrix[k][i] = matrix[i][k];
		matrix[i][k] = tmp;
	}
}
*/