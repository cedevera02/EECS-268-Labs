/*
File name: main.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #8
Date: 11/4/2020
*/

#include <iostream>
#include "Executive.h"
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 6)
    {
        std::cout << "ERROR: Invalid amount of arguments\n";
        exit(1);
    }
    else
    {
        Executive exec(argc,argv);        
    }
    return 0;
}