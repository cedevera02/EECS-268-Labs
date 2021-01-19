/*
File name: main.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #6
Date: 10/14/2020
*/

#include <iostream>
#include <string>
#include "Permutations.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "ERROR: Invalid amount of arguments\n";
    }
    else
    {    
        Permutations perm(argv[1]);
    }
    
    return 0;
}