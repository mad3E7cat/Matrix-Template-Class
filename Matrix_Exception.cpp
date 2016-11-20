#pragma once
#include "Matrix_Exception.h"
#include <cstring>
Matrix_Exception::Matrix_Exception(const char* err)
{
	error = new char[128];
	strcpy(error, err);
}
Matrix_Exception::~Matrix_Exception()
{
	delete error;
}
const char* Matrix_Exception::what()
{
 	return error;
}
