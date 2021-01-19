/*
File name: Elevator.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/


#include "Elevator.h"
#include "myException.h"

Elevator::Elevator() 
{
    m_numPeople = 0;
}

void Elevator::wait(std::string name)
{
    m_line.enqueue(name);
}

void Elevator::pickUp()
{
    if (m_line.isEmpty())
    {
        std::cout << "There is no one to pick up\n";
    }
    else
    {
        if (m_numPeople >= 7)
        {
            throw(myException ("ERROR: Maximum occupancy on elevator\n"));
        }
        else
        {
            for (int i = m_numPeople; i<7; i++)
            {
                try
                {
                    m_elevator.push(m_line.peekFront());
                    m_numPeople++;
                    m_line.dequeue();
                }
                catch (myException& e)
                {
                    std::cout << "ERROR: No one to pick up\n";
                }
            }
        }
        
    }
}

void Elevator::dropOff(int num)
{
    if (num >=0)
    {
        for (int i = 0; i < num; i++)
        {
            if (i > 7)
            {
                throw(myException("ERROR: There is no one else to drop off\n"));
            }
            else
            {
                try
                {
                    m_elevator.pop();
                    m_numPeople--;
                }
                catch (myException& e)
                {
                    std::cout << "No one else to drop off\n";
                }
            }
        }
    }
    else
    {
        throw (myException("ERROR: Invalid drop off amount\n"));
    }
}

void Elevator::inspection()
{
    std::cout << "Elevator Status:\n";
    if (m_elevator.isEmpty())
    {
        std::cout << "The elevator is empty.\n";
        std::cout << "No one is in the elevator.\n";
    }
    else
    {
        std::cout << "The elevator is not empty.\n";
        try
        {
            std::cout << m_elevator.peek() << " is next to leave the elevator.\n";
        }
        catch (myException& e)
        {
            std::cout << "No one is in the elevator.\n";
        }
    }
    if (m_line.isEmpty())
    {
        std::cout << "No one is next in line.\n";
    }
    else
    { 
        try
        {
            std::cout << m_line.peekFront() << " will be the next person to get on the Elevator.\n";
        }
        catch(myException& e)
        {
            std::cout << "No one is next in line.\n";
        }
    }
    
}