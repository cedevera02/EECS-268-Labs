/*File name: Rectangle.h
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #2
*Date: 9/9/2020
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>

class Rectangle: public Shape
{
    private:

    double m_length;
    double m_width;

    public:

    double area() const;
    //@pre - m_length and m_width must have valid variables
    //@post - calculates the area of the Rectangles using the formula m_length*m_width,
    // does not change member variables
    //@return returns calculated area

    std::string shapeName() const;
    //@return - returns the string "Rectangle";

    void setLength(double length);
    //@post - sets the variable in length to m_length

    void setWidth(double width);
    //@post - sets the variable in width to m_width
    

};

#endif
