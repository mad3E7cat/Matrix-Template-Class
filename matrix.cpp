#pragma once
#include "matrix.h"
#include "Matrix_Exception.h"
template <typename T>
Matrix_Template<T>::Matrix_Template(int _rows, int _columns)
{
    row = _rows;
	column = _columns;
	arr_ptr = new T*[_rows];
	for(int i = 0; i < _rows; i++)
	{
		arr_ptr[i] = new T[_columns];
	}
}
template<typename T>
Matrix_Template<T>::~Matrix_Template()
{
	for(int i = 0; i < row; i++)
	{
		delete []arr_ptr[i];
	}
	delete []arr_ptr;
}
template<typename T>
Matrix_Template<T>::Matrix_Template(Matrix_Template<T>& obj)
{
	row = obj.row;
	column = obj.column;
	arr_ptr = new T*[row];
	for(int i = 0; i < row; i++)
	{
		arr_ptr[i] = new T[column];
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			 T tmp = obj.get(i, j);
			 this->set(i, j, tmp);
		}
	}
}
template<typename T>
T& Matrix_Template<T>::get(int i, int j) // exceptions
{
	if( (i > row) || (j > column))
	{
		throw new Matrix_Exception("There's no such element in this matrix...");
	}
	return arr_ptr[i][j];
}
template<typename T>
void Matrix_Template<T>::set(int i, int j, const T& val) // exceptions
{
	if( (i > row) || (j > column))
	{
		throw new Matrix_Exception("There's no such element in this matrix...");
	}
	arr_ptr[i][j] = val;
}
template<typename T>
int Matrix_Template<T>::rows()
{
	return this -> row;
}
template<typename T>
int Matrix_Template<T>::columns()
{
	return this -> column;
}
std::ostream& operator<< (std::ostream& ostr, const Point& pt)
{
	ostr << "\nX:" << pt.x << "\nY:" << pt.y << "\nZ:" << pt.z << std::endl;
	return ostr; 
}
template<typename T>
void Matrix_Template<T>::sum(Matrix_Template<T>& obj) // exceptions
{
	if((row != obj.row) || (column != obj.column))
	{
		throw new Matrix_Exception("Addition is impossible. Matrices are not equal in rows/columns...");
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			T temp, temp2;
			temp = this->get(i, j);
			temp2 = obj.get(i, j);
			this->set(i, j, (temp + temp2));
		}
	}
}
template<typename T>
Matrix_Template<T>& Matrix_Template<T>::operator=(Matrix_Template<T>& obj)
{
	
	if((column == obj.columns()) && (row == obj.rows()))
	{
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < column; j++)
			{
				arr_ptr[ i ][ j ] = obj.get(i, j);
			}
		}
	}
	else // if column != obj.column OR row != obj.row
	{
		//firstly we clear our old mathrix array
		for(int i = 0; i < row; i++)
		{
			delete []arr_ptr[ i ]; // may need []
		}
		delete []arr_ptr; // may need []
		//now we allocate the new one
		arr_ptr = new T*[ obj.rows() ]; // obj.rows size array of pointers
		for(int i = 0; i < obj.rows(); i++)
		{
			arr_ptr[ i ] = new T[ obj.columns() ]; // every pointer points to T array of obj.column size
		}
		// reinit other fields:
		column = obj.columns();
		row = obj.rows();
		// now copy arr_ptr array of obj to our new array
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < column; j++)
			{
				arr_ptr[ i ][ j ] = obj.get(i, j);
			}
		}
	}
	return *this;
}

template<typename T>
Matrix_Template<T>& Matrix_Template<T>::rotate()
{
	//constr change rows and columns
	Matrix_Template<T> temp(*this);
	//change rows-columns of rotated
	row = temp.columns();
	column = temp.rows(); 
	// dealloc 2d array allocated in constructor
	// for(int i = 0; i < rotated.rows(); i++)
	// {
	// 	delete []rotated.arr_ptr[ i ]; // may need []
	// }
	// delete []rotated.arr_ptr; // may need []
	// new alloc
	arr_ptr = new T*[ row ]; 
	for(int i = 0; i < row; i++)
	{
		arr_ptr[ i ] = new T[ column ];
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			arr_ptr[ i ][ j ] = temp.arr_ptr[ j ][ i ];
		}
		str_inv(arr_ptr[ i ], column);
	}
	return *this;
}

template<typename T>
Matrix_Template<T>& Matrix_Template<T>::transponate()
{
	//constr change rows and columns
	Matrix_Template<T> temp(*this);
	//change rows-columns of rotated
	row = temp.columns();
	column = temp.rows(); 
	// dealloc 2d array allocated in constructor
	// for(int i = 0; i < rotated.rows(); i++)
	// {
	// 	delete []rotated.arr_ptr[ i ]; // may need []
	// }
	// delete []rotated.arr_ptr; // may need []
	// new alloc
	arr_ptr = new T*[ row ]; 
	for(int i = 0; i < row; i++)
	{
		arr_ptr[ i ] = new T[ column ];
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			arr_ptr[ i ][ j ] = temp.arr_ptr[ j ][ i ];
		}
		//for transponation no need str_inv(arr_ptr[ i ], column);
	}
	return *this;
}

template<typename T>
void Matrix_Template<T>::str_inv(T* arr, int size)
{
	T* tmp = new T[size];
	for(int i = size - 1, j = 0; i >= 0; i--, j++)
	{
		tmp[ j ] = arr[ i ];
	}
	for(int i = 0; i <= size; i++)
	{
		arr[ i ] = tmp[ i ];
	}
	delete []tmp;
}

Point& operator+ (Point& lft, Point& rght)
{
	lft.x += rght.x;
	lft.y += rght.y;
	lft.z += rght.z;
	return lft;
}
