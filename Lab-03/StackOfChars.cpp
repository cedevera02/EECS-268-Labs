/*
File name: StackOfChars.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #3
Date: 9/16/2020
*/

#include "Node.h"
#include "StackOfChars.h"
#include <stdexcept>
#include <iostream>
#include <string>

StackOfChars::StackOfChars()
{
    m_top = nullptr;
}

StackOfChars::StackOfChars(const StackOfChars& orig)
{
    if (orig.isEmpty())
    {
        m_top = nullptr;
    }
    else
        {
        Node* temp, *temp2;
        temp = orig.m_top;
        m_top = new Node(temp->getEntry());
        temp2 = m_top;
        try
        {
            while (temp->getNext()!= nullptr)
            {
                temp = temp->getNext();
                temp2->setNext(new Node(temp->getEntry()));
                temp2 = temp2->getNext();
            }
        }
        catch (std::runtime_error& rte)
        {
            temp2->setNext(nullptr);
        }
    }
}

StackOfChars::~StackOfChars()
{
    Node* temp;
    while (m_top != nullptr)
    {
        try
        {
            temp = m_top->getNext();
        }
        catch (std::runtime_error& rte)
        {
                temp = nullptr;
        }       
        delete m_top;
        m_top = temp;
    }

}

void StackOfChars::operator=(const StackOfChars& rhs)
{
    if (rhs.isEmpty())
    {
        m_top = nullptr;
    }
    else
        {
        Node* temp, *temp2;
        temp = rhs.m_top;
        m_top = new Node(temp->getEntry());
        temp2 = m_top;
        try
        {
            while (temp->getNext()!= nullptr)
            {
                temp = temp->getNext();
                temp2->setNext(new Node(temp->getEntry()));
                temp2 = temp2->getNext();
            }
        }
        catch (std::runtime_error& rte)
        {
            temp2->setNext(nullptr);
        }
    }
}
	
void StackOfChars::push(char entry)
{
    if (m_top == nullptr)
    {
        m_top = new Node(entry);
    }
    else
    {
        Node* temp = m_top;
        m_top = (new Node(entry));
        m_top->setNext(temp);
    }
}

void StackOfChars::pop()
{
    if (!(isEmpty()))
    {
        Node* temp;
        try
        {
            temp = m_top->getNext();
            delete m_top;
            m_top = temp;
        }
        catch(std::runtime_error& rte)
        {
            delete m_top;
            m_top = nullptr;
        }
    }
    else
    {
        throw(std::runtime_error ("Already Empty"));
    }
    
}

char StackOfChars::peek() const
{
    if (!isEmpty())
    {   
        return (m_top->getEntry());
    }
    else
    {
        throw (std::runtime_error ("Empty"));
    }
}

bool StackOfChars::isEmpty() const
{
    if (m_top == nullptr)
    {
        return true;
    }
    return false;
}