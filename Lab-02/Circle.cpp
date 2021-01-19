/*File name: Circle.cpp
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #2
*Date: 9/9/2020
*/

#include "Shape.h"
#include "Circle.h"
#include <iostream>


double Circle::area() const
{
    return (3.141590083*m_radius*m_radius);
}

std::string Circle::shapeName() const
{
    return ("Circle");
}

void Circle::setRadius(double radius)
{
    m_radius = radius;
}