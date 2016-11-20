#pragma once
//#ifndef _MATRIX_
//#define _MATRIX_
#include <ostream>
typedef struct Point
{
	int x;
	int y;
	int z;
} Point;
///////////////
template<typename T>
class Matrix_Template
{
private:
	T** arr_ptr;
	int column;
	int row;
public:
	Matrix_Template(int _rows = 0, int _columns = 0);
	~Matrix_Template();
	T& get(int i, int j); // exceptions
    void set(int i, int j, const T& val); // exceptions
    Matrix_Template<T>& rotate();
    Matrix_Template<T>& transponate();
	int rows();
	int columns();
	void sum(Matrix_Template<T>& obj); // exceptions
	Matrix_Template(Matrix_Template<T>& obj);
    Matrix_Template<T>& operator=(Matrix_Template<T>& obj);
    void str_inv(T* arr, int size);
};
#include "matrix.cpp"
/////////////////////////////////Point structure
std::ostream& operator<< (std::ostream& ostr, Point& pt);
//#endif