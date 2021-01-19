/*
File name: main.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #6
Date: 10/14/2020
*/

#include <iostream>
#include "Parenthesis.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "ERROR: You have input in the wrong number of arguments\n";
        exit(1);
    }
    else
    {
        //std::string word = argv[1];
        Parenthesis parens(argv[1]);
    }
}