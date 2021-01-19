/*
File name: Stack.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #6
Date: 10/14/2020
*/

#include <stdexcept>
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
        throw(std::runtime_error ("Already Empty"));
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
        throw (std::runtime_error ("Empty"));
    }
}

template <typename T>
T Stack<T>::peek(int index) const
{
    if (!isEmpty())
    {   
        Node<T>* curr = m_top;
        for (int i = 1; i <=index; i++)
        {
            curr = curr->getNext();
        }
        return (curr->getEntry());
    }
    else
    {
        throw (std::runtime_error ("Empty"));
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

template <typename T>
int Stack<T>::numOfN()
{
    int num = 0;
    Node<T>* curr = m_top;
    while (curr != nullptr)
    {
        num++;
        curr = curr->getNext();
    }
    return num;
}