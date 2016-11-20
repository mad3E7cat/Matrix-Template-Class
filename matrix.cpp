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
	return row;
}
template<typename T>
int Matrix_Template<T>::columns()
{
	return column;
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
	if((this->row == obj.row) && (this->column == obj.column))
	{
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < column; j++)
			{
				arr_ptr[ i ][ j ] = obj.arr_ptr[ i ][ j ];
			}
		}
		return *this;
	}
	if((column != obj.column) || (row != obj.row))
	{
		for(int i = 0; i < row; i++)
		{
			delete []arr_ptr[i];
		}
		delete []arr_ptr; // free array
		column = obj.column;
		row = obj.row;
		arr_ptr = new T*[obj.row];
		for(int i = 0; i < obj.row; i++)
		{
			arr_ptr[i] = new T[obj.column];
		} // allocate new one
		for(int i = 0; i < obj.row; i++)
		{
			for(int j = 0; j < obj.column; j++)
			{
				arr_ptr[ i ][ j ] = obj.arr_ptr[ i ][ j ];
			}
		}
	}
	return *this;
}
template<typename T>
Matrix_Template<T>& Matrix_Template<T>::rotate()
{
	Matrix_Template<T> temp_m(*this); //rotated_cp(this->column, this->row),
	Matrix_Template<T> rotated(column, row);
	//constr change rows and columns
	//change temp_m to this
	for(int i = 0; i < row; i++)
	{
		delete []arr_ptr[i];
	}
	delete []arr_ptr; //free
	rotated.row = column;
	rotated.column = row;//change rows-columns
	rotated.arr_ptr = new T*[rotated.row];// new alloc
	for(int i = 0; i < rotated.row; i++)
	{
		rotated.arr_ptr[ i ] = new T[ rotated.column ];
	}
	for(int i = 0; i < rotated.row; i++)
	{
		for(int j = 0; j < rotated.column; j++)
		{
			rotated.arr_ptr[ i ][ j ] = temp_m.arr_ptr[ j ][ i ];
		}
		str_inv(rotated.arr_ptr[i], rotated.column);
	}
	return rotated;
}

template<typename T>
Matrix_Template<T>& Matrix_Template<T>::transponate() 
{
	Matrix_Template<T> temp_m(*this), rotated_cp(*this);
	for(int i = 0; i < rotated_cp.rows(); i++)
	{
		delete []rotated_cp.arr_ptr[i];
	}
	delete []rotated_cp.arr_ptr; //free
	rotated_cp.row = rotated_cp.columns();
	rotated_cp.column = rotated_cp.rows();//change rows-columns
	rotated_cp.arr_ptr = new T*[rotated_cp.rows()];// new alloc
	for(int i = 0; i < rotated_cp.rows(); i++)
	{
		rotated_cp.arr_ptr[ i ] = new T[ rotated_cp.columns() ];
	}
	for(int i = 0; i < rotated_cp.rows(); i++)
	{
		for(int j = 0; j < rotated_cp.columns(); j++)
		{
			rotated_cp.arr_ptr[ i ][ j ] = temp_m.arr_ptr[ j ][ i ];
		}
	}
	return rotated_cp;
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
