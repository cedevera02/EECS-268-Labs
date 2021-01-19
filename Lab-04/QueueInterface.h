/*
File name: QueueInterface.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

template <typename T>
class QueueInterface
{
    public: 
    virtual ~QueueInterface() {}

    /**
     * @returns true if the stack is empty, false otherwise
     * */
    virtual bool isEmpty() const = 0;

    /**
     * @param value is the value addded into the queue
     * @post Entry added to back of queue
     * */
    virtual void enqueue(const T value) = 0;

    /**
     * @pre queue must not be empty
     * @post front of the front is removed
     * @throw throws std::runtime_error if attempted on an empty queue. Does not return a value in this case.
     * */
    virtual void dequeue() = 0;

    /**
     * @pre queue is not empty
     * @return the value at the front of the stack
     * @throw throws an std::runtime_error if attempted on an empty queue. Does not return a value in this case
     * */
    virtual T peekFront() const = 0;
};

#endif