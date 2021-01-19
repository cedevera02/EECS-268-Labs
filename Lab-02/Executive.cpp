/*File name: Executive.cpp
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #2
*Date: 9/9/2020
*/

#include "Executive.h"
#include <fstream>

Executive::Executive(std::string file)
{
    m_fileName = file;
}

void Executive::print(int index)
{
    std::cout << "Shape at index " << index << ": " ;
    try
    {
        std::cout << m_container->shapeName(index) << " area = ";
        std::cout << m_container->area(index) << '\n';
    }
    catch (std::runtime_error& rte)
    {
        std::cout << rte.what() << '\n';
    }
}

void Executive::run()
{
    std::ifstream input;
    int numShapes, index;
    double val1, val2;
    std::string name, command;
    input.open (m_fileName);
    if (input.is_open())
    {
        input >> numShapes;
        m_container = new ShapeContainer(numShapes);

        do
        {
            input >> command;
            if (command == "ADD")
            {
                input >> index >> name;
                if (name == "CIR")
                {
                    input >> val1;
                    Circle* circ = new Circle;
                    circ->setRadius(val1);
                    try
                    {
                        m_container->add(circ,index);
                    }
                    catch(std::runtime_error& e)
                    {
                        std::cout << e.what() << '\n';
                    }                    
                }
                if (name == "REC")
                {
                    input >> val1 >> val2;
                    Rectangle* rect = new Rectangle;
                    rect->setLength(val1);
                    rect->setWidth(val2);
                    try
                    {
                        m_container->add(rect, index);
                    }
                    catch(std::runtime_error& e)
                    {
                        std::cout << e.what() << '\n';
                    }
                    
                    
                }  
                if (name == "TRI")
                {
                    input >> val1 >> val2;
                    Triangle* tri = new Triangle;
                    tri->setBase(val1);
                    tri->setHeight(val2);
                    try
                    {
                        m_container->add(tri, index);
                    }
                    catch(std::runtime_error& e)
                    {
                        std::cout << e.what() << '\n';
                    }
                }              
            }
            if (command == "DELETE")
            {
                input >> index;
                try
                {
                    m_container->
                    remove(index);
                }
                catch(std::runtime_error& e)
                {
                    std::cout << e.what() << '\n';
                }
            }
            if (command == "PRINT")
            {
                input >> index;
                print(index);
            }
        } while(command!="EXIT");

    }

    input.close();
    
}
