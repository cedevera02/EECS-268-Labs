/*
File name: Queue.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#include "Node.h"
#include "myException.h"

template <typename T>
Queue<T>::Queue()
{
    m_front = nullptr;
    m_back = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    Node<T>* temp;
    while (m_front!=m_back)
    {
        temp = m_front;
        m_front = m_front->getNext();
        delete temp;
    }
    delete m_front;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    if (m_front == nullptr && m_back == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
void Queue<T>::enqueue(T value)
{
    Node<T>* temp = new Node<T>(value);
    if (isEmpty())
    {
        m_front = temp;
        m_back = temp;
    }
    else
    {
        m_back->setNext(temp);
        m_back = m_back->getNext();
    }
}

template <typename T>
void Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw(myException ("ERROR: Dequeue not possible in empty Queue\n"));
    }
    else
    {
        if (m_front == m_back)
        {
            delete m_front;
            m_front = nullptr;
            m_back = nullptr;
        }
        else
        {
            Node<T>* temp;
            temp = m_front;
            m_front = m_front->getNext();
            delete temp;
        }
    }
}

template <typename T>
T Queue<T>::peekFront() const
{
    if (isEmpty())
    {
        throw(myException ("ERROR: Cannot peek at an empty queue\n"));
    }
    else
    {
        return (m_front->getEntry());
    }
}