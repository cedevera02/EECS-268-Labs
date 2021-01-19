/*
File name: Node.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#include "Node.h"
#include "myException.h"
#include <iostream>
#include <string>

template <typename T>
Node<T>::Node(T entry)
{
    m_entry = entry;
    m_next = nullptr;
}

template <typename T>
T Node<T>::getEntry() const
{
    return m_entry;
}

template <typename T>
void Node<T>::setEntry(T entry)
{
    m_entry = entry;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
        return m_next;  
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
    m_next = next;
}