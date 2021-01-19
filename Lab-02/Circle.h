/*File name: Circle.h
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #2
*Date: 9/9/2020
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iostream>

class Circle: public Shape
{
    private:

    double m_radius;

    public:

    double area() const;
    //@ pre - m_radius must contain a valid variable
    //@post - calculates area with the formula 3.141590083*m_radius*m_radius
    //@return - returns calculated area

    std::string shapeName() const;
    //@return - returns a string "Circle"

    void setRadius(double radius);
    //@post - sets m_radius = radius



};

#endif