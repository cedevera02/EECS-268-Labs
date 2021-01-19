/*
File name: Fibonacci.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #6
Date: 10/14/2020
*/

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <string>
#include <iostream>
#include <stdexcept>

class Fibonacci
{
    public:
    /**
     * @pre none
     * @post calls run function
     * @param response inserted into run as the first parameter
     * @param subject inserted into run as second paramter
     **/
    Fibonacci(std::string response, int subject);

    /**
     * @pre none
     * @post solves the fibonacci sequence at the given value
     * @param ith the index of the fibonacci number wanted
     * @return returns the ith fibonacci number
     **/
    int fib(int ith);

    /**
     * @pre none
     * @post runs the program
     * @param response -i or -v to detrmine what to run
     * @param subject number the function will be dealing with to either verify or find the fib of
     **/
    void run(std::string response, int subject);

    /**
     * @pre none
     * @post verifies whether the given value is in the fibonacci sequence
     * @param subject number to be verified in the fibonacci sequence
     * @return true if subject is in fib, false if not
     **/
    bool verify(int subject);
};

#endif