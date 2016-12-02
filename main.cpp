#include <iostream>
#include "matrix.h"
#include "Matrix_Exception.h"
using namespace std;
int main()
{
	Matrix_Template<int> matrix1(1,3);
	Matrix_Template<int> matrix2(2,4);
	//BEGIN MATRICES INPUT
	cout << "\n\n1:\n";
	for(int i = 0; i < matrix1.rows(); i++)
	{
		for(int j = 0; j < matrix1.columns(); j++)
		{
			int tmp = 0;
			cout << "[" << i << "]" << "[" << j << "] : ";
			cin >> tmp;
			matrix1.set(i, j, tmp);
		}
	}
	cout << "\n\n2:\n";
	for(int i = 0; i < matrix2.rows(); i++)
	{
		for(int j = 0; j < matrix2.columns(); j++)
		{
			int tmp = 0;
			cout << "[" << i << "]" << "[" << j << "] : ";
			cin >> tmp;
			matrix2.set(i, j, tmp);
		}
	}
	//END MATRICES INPUT
	cout << "\n\nmatrix1: \n";
	for(int i = 0; i < matrix1.rows(); i++)
	{
		cout << "\n\n";
		for(int j = 0; j < matrix1.columns(); j++)
		{
			cout << matrix1.get(i, j) << " ";
		}
	} 
	cout << "\n\nmatrix2: \n";
	for(int i = 0; i < matrix2.rows(); i++)
	{
		cout << "\n\n";
		for(int j = 0; j < matrix2.columns(); j++)
		{
			cout << matrix2.get(i, j) << " ";
		}
	}
	Matrix_Template<int> matrix3(matrix1); 
	//matrix1 = matrix2 = matrix3 = matrix2;
	//matrix3 = matrix2.rotate().rotate();
	matrix3 = matrix2.transponate();
	matrix1 = matrix3;
	cout << "\n\nM1:\n";
	for(int i = 0; i < matrix1.rows(); i++)
	{
		cout << "\n\n";
		for(int j = 0; j < matrix1.columns(); j++)
		{
			cout << matrix1.get(i, j) << " ";
		}
	}
	cout << "\n\nM2:\n";
	for(int i = 0; i < matrix2.rows(); i++)
	{
		cout << "\n\n";
		for(int j = 0; j < matrix2.columns(); j++)
		{
			cout << matrix2.get(i, j) << " ";
		}
	}
	return 0;
}
