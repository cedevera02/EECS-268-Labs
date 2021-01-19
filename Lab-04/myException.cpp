/*
File name: myException.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#include "myException.h"
#include <stdexcept>

myException::myException(const char* message): std::runtime_error(message) //your constructor calls runtime error’s constructor
{

}