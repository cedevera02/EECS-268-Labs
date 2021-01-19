/*File name: Executive.h
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #2
*Date: 9/9/2020
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include "Shape.h"
#include "ShapeContainer.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

class Executive
{
    private:
    std::string m_fileName;
    ShapeContainer* m_container;

    public:
    Executive(std::string file);
    //@post - sets string file into m_fileName;
    
    void print(int index);
    //@pre - m_container must contain valid ShapeContainer and must have Shapes stored
    //@post - gathers necessary information to print out Name and area of shape from certain index

    void run();
    //@pre - m_fileName must have valid string that corresponds with a file in the folder to read in from
    //@post - reads in instructions from file and creates the array specified into m_container
};

#endif