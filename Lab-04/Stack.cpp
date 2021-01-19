/*
File name: Stack.cpp
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
Stack<T>::Stack()
{
    m_top = nullptr;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& orig)
{
    if (orig.isEmpty())
    {
        m_top = nullptr;
    }
    else
        {
        Node<T>* temp, *temp2;
        temp = orig.m_top;
        m_top = new Node<T>(temp->getEntry());
        temp2 = m_top;
        while (temp->getNext()!= nullptr)
        {
            temp = temp->getNext();
            temp2->setNext(new Node<T>(temp->getEntry()));
            temp2 = temp2->getNext();
        }
    }
}

template <typename T>
Stack<T>::~Stack()
{
    Node<T>* temp;
    while (m_top != nullptr)
    {
        temp = m_top->getNext();     
        delete m_top;
        m_top = temp;
    }

}

template <typename T>
void Stack<T>::operator=(const Stack<T>& rhs)
{
    if (rhs.isEmpty())
    {
        m_top = nullptr;
    }
    else
    {
        Node<T>* temp, *temp2;
        temp = rhs.m_top;
        m_top = new Node<T>(temp->getEntry());
        temp2 = m_top;
        while (temp->getNext()!= nullptr)
        {
            temp = temp->getNext();
            temp2->setNext(new Node<T>(temp->getEntry()));
            temp2 = temp2->getNext();
        }
    }
}

template <typename T>
void Stack<T>::push(T entry)
{
    Node<T>* filler = new Node<T>(entry);
    if (m_top == nullptr)
    {
        m_top = filler;
    }
    else
    {
        Node<T>* temp = m_top;
        m_top = filler;
        m_top->setNext(temp);
    }
}

template <typename T>
void Stack<T>::pop()
{
    if (!(isEmpty()))
    {
        Node<T>* temp;
        temp = m_top->getNext();
        delete m_top;
        m_top = temp;
    }
    else
    {
        throw(myException("Already Empty"));
    }
    
}

template <typename T>
T Stack<T>::peek() const
{
    if (!isEmpty())
    {   
        return (m_top->getEntry());
    }
    else
    {
        throw (myException ("Empty"));
    }
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    if (m_top == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}