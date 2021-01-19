/*
File name: Makefile
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #9
Date: 11/11/2020
*/

#include <iostream>
#include "Executive.h"

int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        std::cout << "ERROR: Invalid amount of command line arguments1\n";
        exit(1);
    }
    else
    {
        Executive exec(argv[1]);
    }
    return 0;
}