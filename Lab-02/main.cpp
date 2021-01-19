/*File name: main.cpp
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #2
*Date: 9/9/2020
*/

#include <iostream>
#include "Shape.h"
#include "Executive.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Wrong number of arguments\n";
        exit(1);
    }
    else
    {
        Executive exect(argv[1]);
        exect.run();
    }
    
    return 0;
}