/*
File name: Executive.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <fstream>
#include <iostream>
#include <string>
#include "Elevator.h"
#include "myException.h"

class Executive
{
    private: 
    Elevator m_system;
    std::string m_fileName;

    public:

    Executive(std::string file);

    void run();
};

#endif