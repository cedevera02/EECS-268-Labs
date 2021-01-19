/*File name: Triangle.cpp
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #2
*Date: 9/9/2020
*/

#include "Shape.h"
#include "Triangle.h"
#include <iostream>

double Triangle::area() const
{
    return (0.5*m_base*m_height);
}

std::string Triangle::shapeName() const
{
    return ("Triangle");
}

void Triangle::setBase(double base)
{
    m_base = base;
}

void Triangle::setHeight(double height)
{
    m_height = height;
}