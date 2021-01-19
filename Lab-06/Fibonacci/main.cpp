/*
File name: main.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #6
Date: 10/14/2020
*/

#include <iostream>
#include <string>
#include "Fibonacci.h"

int main(int argv, char* argc[])
{
    if (argv !=3)
    {
        std::cout << "ERROR: Invalid amount of arguments\n";
        exit(1);
    }
    else
    {
        int integerConv = std::stoi(argc[2]);
        Fibonacci fibby(argc[1],integerConv);
    }
    return 0;
}