/*
File name: myException.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/
#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

#include <stdexcept>

class myException: public std::runtime_error //inheriting from runtime error
{
    public:
    myException(const char* message); //your constructor and only method
};

#endif