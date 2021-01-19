/*File name: ShapeContainer.cpp
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #2
*Date: 9/9/2020
*/

#include "Shape.h"
#include "ShapeContainer.h"
#include <stdexcept>

ShapeContainer::ShapeContainer(int size)
{
    m_size = size;
    m_arrayOfShapes = new Shape*[size];
    for (int i = 0; i<size; i++)
    {
        m_arrayOfShapes[i] = nullptr;
    }
}

ShapeContainer::~ShapeContainer()
{
    for (int i =0; i <m_size; i++ )
    {
        delete m_arrayOfShapes[i];
    }
    delete [] m_arrayOfShapes;
}

double ShapeContainer::area(int index) const
{
    if (index < m_size)
    {
        return (m_arrayOfShapes[index]->area());
    }
    else
    {
        throw (std::runtime_error("Does not exist"));
    }
} 

std::string ShapeContainer::shapeName(int index) const
{
    if (index < m_size)
    {
        return (m_arrayOfShapes[index]->shapeName());
    }
    else
    {
        throw (std::runtime_error("Does not exist"));
    }
}

void ShapeContainer::add(Shape* shapePtr, int index)
{
    if (index > m_size || shapePtr==nullptr)
    {
        throw (std::runtime_error("Does not exist"));
    }
    else
    {
        (m_arrayOfShapes[index] = shapePtr);     
    }
}

void ShapeContainer::remove(int index)
{
    if (index > m_size || m_arrayOfShapes[index]==nullptr)
    {
        throw (std::runtime_error("Does not exist"));
    }
    else
    {
        (delete m_arrayOfShapes[index]);

    }
}