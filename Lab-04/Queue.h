/*
File name: Queue.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "QueueInterface.h"
#include "Node.h"

template <typename T>
class Queue: public QueueInterface<T>
{ 
    private:
    Node<T>* m_front;
    Node<T>* m_back;
    
    public:

    Queue();

    ~Queue();

    /**
     * @returns true if the stack is empty, false otherwise
     * */
    bool isEmpty() const;

    /**
     * @param value is the value addded into the queue
     * @post Entry added to back of queue
     * */
    void enqueue(T value);

    /**
     * @pre queue must not be empty
     * @post front of the front is removed
     * @throw throws std::runtime_error if attempted on an empty queue. Does not return a value in this case.
     * */
    void dequeue();

    /**
     * @pre queue is not empty
     * @return the value at the front of the stack
     * @throw throws an std::runtime_error if attempted on an empty queue. Does not return a value in this case
     * */
    T peekFront() const;
};

#include "Queue.cpp"

#endif