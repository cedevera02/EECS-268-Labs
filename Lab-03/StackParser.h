/*
File name: StackParser.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #3
Date: 9/16/2020
*/

#ifndef STACKPARSER_H
#define STACKPARSER_H

#include "StackOfChars.h"

class StackParser
{
    public:
    StackParser();
    ~StackParser();
    private:
    std::string input;
    StackOfChars sequence;
    int* lengthOfSequence;
    void run();
    bool isBalanced();

};

#endif