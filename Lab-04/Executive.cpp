/*
File name: Executive.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#include "Executive.h"

Executive::Executive(std::string file)
{
    m_fileName = file;
    run();
}

void Executive::run()
{
    std::ifstream input;
    std::string varIn;
    int num;
    input.open(m_fileName);
    if(input.is_open())
    {
        while(input >> varIn)
        {
            if (varIn == "WAIT")
            {
                input >> varIn;
                m_system.wait(varIn);
            }
            else if (varIn == "PICK_UP")
            {
                try
                {
                    m_system.pickUp();
                }
                catch(myException& e)
                {
                    std::cout << e.what() << '\n';
                }
                
            }
            else if (varIn == "DROP_OFF")
            {
                input >> num;
                try
                {
                    m_system.dropOff(num);    
                }
                catch (myException& e)
                {
                    std::cout << e.what() << '\n';
                }  
            }
            else if (varIn == "INSPECTION")
            {
                m_system.inspection();
            }
        }
    }
    else
    {
        std::cout << "ERROR: The file name you input in is invalid. Exiting...\n";
        exit(1);
    }
}
