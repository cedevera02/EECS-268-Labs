/*
File name: main.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #3
Date: 9/16/2020
*/

#include <iostream>
#include <string.h>
#include "StackTester.h"
#include "StackOfChars.h"
#include "StackParser.h"


int main (int argc, char* argv[])
{
    if (argc <2)
    {
        std::cout <<"ERROR: Invalid amount of commands\n";
        exit (1);
    }
    else
    {
        std::string s(argv[1]);
        if (s == "-t")
        {
            StackTester tester;
        }
        if (s == "-p")
        {
            StackParser parser;
        }
    }
    return 0;
}