#pragma once
//#ifndef MATRIX_EXCEPTION
//#define MATRIX_EXCEPTION
class Matrix_Exception
{
private:
	char* error;
public:
	Matrix_Exception(const char* err);
	~Matrix_Exception();
	const char* what();
};
#include "Matrix_Exception.cpp"
//#endif