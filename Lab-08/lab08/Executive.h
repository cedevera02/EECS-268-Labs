/*
File name: Executive.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #8
Date: 11/4/2020
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Sorts.h"
#include "SortTimer.h"
#include "ArrayCreator.h"
#include <time.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cassert>

class Executive
{
    private:

    bool m_assert;
    int** m_array;
    int m_MAX;
    std::string m_sort;
    std::string m_file;
    ArrayCreator<int>* m_creator;

    public:

    Executive(int argc, char* argv[]);

    ~Executive();

    /**
     * @brief fills m_array with random ints
     */
    void fillArray();

    /**
     * @brief prints out m_array
     */
    void printArray();

    /**
     * @brief tests the m_array using m_sort specified and outputs the results into a file
     */
    void testArrays();

    /**
     * @brief tests the m_array with an asser using m_sort specified and outputs the results into a file
     */
    void testArraysAssert();

};

#endif