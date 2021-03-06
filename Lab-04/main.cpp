/*
File name: main.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#include <iostream>
#include <string>
#include "Executive.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "ERROR: Invalid amount of arguments\n";
        exit(1);
    }
    else
    {
        Executive exec(argv[1]);
    }
    return 0;
}