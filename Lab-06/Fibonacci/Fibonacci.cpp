/*
File name: Fibonacci.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #6
Date: 10/14/2020
*/

#include "Fibonacci.h"

Fibonacci::Fibonacci(std::string response, int subject)
{
    run (response, subject);
}

int Fibonacci::fib(int ith)
{
    if (ith == 0)
    {
        return 0;
    }
    else if (ith == 1)
    {
        return 1;
    }
    else
    {
        return (fib(ith-1) + fib(ith-2));
    }
}

void Fibonacci::run(std::string response, int subject)
{
    if (subject >= 0)
    {
        if (response == "-i")
        {
            std::cout << fib(subject) << '\n';
        }
        else if (response == "-v")
        {

            if (verify(subject))
            {
                std::cout << subject  << " is in the sequence\n";
            }
            else
            {
                std::cout << subject << " is not in the sequence\n";
            }
        }
        else
        {
            std::cout << "ERROR: The flag input is not valid\n";
        }
    }
    else
    {
        std::cout << "ERROR: The integer input is negative. NOT VALID\n"; 
    }
}

bool Fibonacci::verify(int subject)
{
    int i = 0;
    bool subPresent = false;
    do
    {
        if (fib(i) == subject)
        {
            subPresent = true;
        }
        i++;        
    } while (fib(i) <= subject);
    return subPresent;
}