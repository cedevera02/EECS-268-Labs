/*
File name: Executive.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #5
Date: 10/3/2020
*/

#include "Executive.h"

Executive::Executive(std::string file)
{
    run(file);
}

void Executive::run(std::string file)
{
    std::ifstream input;
    std::string varIn;
    input.open(file);
    if(input.is_open())
    {
        while(input >> varIn)
        {
            if (varIn == "NAVIGATE")
            {
                input >> varIn;
                m_browser.navigateTo(varIn);
            }
            else if (varIn == "BACK")
            {
                m_browser.back();
                
            }
            else if (varIn == "FORWARD")
            {
                m_browser.forward();      
            }
            else if (varIn == "HISTORY")
            {
                m_browser.printHistory();
            }
        }
    }
    else
    {
        std::cout << "ERROR: The file name you input in is invalid. Exiting...\n";
        exit(1);
    }
}