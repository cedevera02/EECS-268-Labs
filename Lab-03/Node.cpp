/*
File name: Node.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #3
Date: 9/16/2020
*/

#include "Node.h"
#include <stdexcept>
#include <iostream>

Node::Node(char entry)
{
    m_entry = entry;
}

char Node::getEntry() const
{
    return m_entry;
}

void Node::setEntry(char entry)
{
    m_entry = entry;
}

Node* Node::getNext() const
{
    if (m_next != nullptr)
    {
        return m_next;
    }
    else
    {
        throw(std::runtime_error ("Empty"));
    }
    
}

void Node::setNext(Node* next)
{
    m_next = next;
}