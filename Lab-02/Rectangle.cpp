/*File name: Rectangle.cpp
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #2
*Date: 9/9/2020
*/

#include "Shape.h"
#include "Rectangle.h"
#include <iostream>

double Rectangle::area() const
{
    return (m_length*m_width);
}

std::string Rectangle::shapeName() const
{
    return ("Rectangle");
}

void Rectangle::setLength(double length)
{
    m_length = length;
}

void Rectangle::setWidth(double width)
{
    m_width = width;
}