/*
*File name: main.cpp
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #7
*Date: 10/21/2020
*/

#include <iostream>
#include "MazeWalker.h"

int main(int argc, char* argv[])
{
    if (argc !=2)
    {
        std::cout << "ERROR: Invalid amount of command line arguments\n";
        exit(1);
    }
    else
    {
        MazeWalker maze(argv[1]);
        maze.solveMaze();
    }

    return 0;
}