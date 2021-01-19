/*
File name: Executive.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #5
Date: 10/3/2020
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "BrowserHistory.h"
#include <fstream>

class Executive
{
    private:
    BrowserHistory m_browser;
    public:
    Executive(std::string file);

    /**
     * @pre none
     * @post reads in from file to take commands that run the program
     * @param file name of input file
     **/
    void run(std::string file);
};

#endif