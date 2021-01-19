/*
File name: LinkedList.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #5
Date: 10/3/2020
*/

template <typename T>
LinkedList<T>::LinkedList()
{
    m_front = nullptr;
    m_length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
void LinkedList<T>::insert(int index, T entry)
{
    Node<T>* before, *after, *target;
    target = new Node<T>(entry);

    if (index <=0 || index > m_length+1)
    {
        throw (std::runtime_error ("ERROR: Invalid index"));
    }
    else if (index == 1)
    {
        after = m_front;
        m_front = target;
        m_front->setNext(after);
        m_length++;
    }
    else
    {
        before = m_front;
        for (int i =1; i < (index-1); i++)
        {
            before = before->getNext();
        }
        after = before->getNext();
        before->setNext(target);
        target->setNext(after);
        m_length++;
    }
    
}

template <typename T>
void LinkedList<T>::remove(int index)
{
    Node<T>* before, *after, *target;
    if (index <=0 || index > m_length)
    {
        throw (std::runtime_error ("ERROR: Index is not valid"));
    }
    else if (index == 1)
    {
        after = m_front->getNext();
        delete m_front;
        m_front = after;
        m_length--;
    }
    else if (index < m_length)
    {
        before = m_front;
        for (int i =1; i < (index-1); i++)
        {
            before = before->getNext();
        }
        target = before->getNext();
        after =target->getNext();
        delete target;
        before->setNext(after);
        m_length--;
    }
    else
    {
        before = m_front;
        for (int i =1; i < index-1; i++)
        {
            before = before->getNext();
        }
        target = before->getNext();
        delete target;
        before->setNext(nullptr);
        m_length--;
    }
}

template <typename T>
T LinkedList<T>::getEntry(int index) const
{
    Node<T>* target;
    if (index <=0 || index > m_length)
    {
        throw (std::runtime_error ("ERROR: Index is not within range"));
    }
    else
    {
        target = m_front;
        for (int i = 1; i < index; i++)
        {
            target = target->getNext();
        }
        return (target->getEntry());
    }
}

template <typename T>
int LinkedList<T>::length() const
{
    int r = m_length;
    return (r);
}

template <typename T>
void LinkedList<T>::clear()
{
    while (m_front != nullptr)
    {
        remove(1);
    }
}

template <typename T>
void LinkedList<T>::setEntry(int index, T entry)
{
    Node<T>* before, *after, *target1, *target = new Node<T>(entry);
    if (index <=0 || index > m_length)
    {
        throw (std::runtime_error ("ERROR: Index is not valid"));
    }
    else if (index == 1)
    {
        after = m_front->getNext();
        delete m_front;
        m_front = target;
        m_front->setNext(after);
    }
    else if (index < m_length)
    {
        before = m_front;
        for (int i =1; i < (index-1); i++)
        {
            before = before->getNext();
        }
        target1 = before->getNext();
        after =target1->getNext();
        delete target1;
        before->setNext(target);
        target->setNext(after);
    }
    else
    {
        before = m_front;
        for (int i =1; i < index-1; i++)
        {
            before = before->getNext();
        }
        target1 = before->getNext();
        delete target1;
        before->setNext(target);
    }
}