/*File name: Triangle.h
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #2
*Date: 9/9/2020
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <iostream>

class Triangle: public Shape
{
    private:

    double m_base;
    double m_height;

    public:

    double area() const;
    //@pre - m_heigth and m_base must have valid variables
    //@post - calculates the area of the Rectangles using the formula 0.5*m_base*m_height,
    // does not change member variables
    //@return returns calculated area

    std::string shapeName() const;
    //@return - returns the string "Triangle"

    void setBase(double base);
    //@post - sets the variable in base to m_base

    void setHeight(double height);
    //@post - sets the variable in height to m_height
    

};

#endif