/*
File name: ArrayCreator.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #8
Date: 11/4/2020
*/


#ifndef ARRAYCREATOR_H
#define ARRAYCREATOR_H

template <typename T>
class ArrayCreator
{
    private: 

    int m_lowerBound;
    int m_upperBound;
    int m_increment;
    T** m_array;

    public:

    ArrayCreator(int lower, int upper, int increment);

    ~ArrayCreator();

    /**
     * @brief creates a two dimensional array based off m_lowerBound, m_upperBound, and m_increment
     */
    void createArray();

    /**
     * @brief makes no changes to array
     * @return returns pointer to 2d array
     */
    T** getArray() const;

    /**
     * @brief makes no changes to array
     * @return returns m_upperBound
     */
    int getUpper() const;

    /**
     * @brief makes no changes to array
     * @return returns m_lowerBound
     */
    int getLower() const;

    /**
     * @brief makes no changes to array
     * @return returns m_increment
     */
    int getIncrement() const;

};

#include "ArrayCreator.cpp"
#endif