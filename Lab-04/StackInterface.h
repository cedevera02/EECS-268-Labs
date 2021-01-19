/*
File name: StackInterface.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

template <typename T>
class StackInterface
{
	public:

       virtual ~StackInterface() {};

	virtual void push(const T entry) = 0;
	
       /** Here's an example of a doxygen comment block. Do this for all methods
       * @pre Stack is non-empty
       * @post Top element is removed from the stack
       * @param None
       * @throw std::runtime_error if pop attempted on empty stack
       **/
	virtual void pop() = 0;
	
       /**
        * @pre Stack is non-empty
        * @post makes no changes
        * @return returns the values stored in m_top
        * @throw if m_top is null, throws a runtime error
        **/
	virtual T peek() const = 0;

       /**
        * @post makes no changes 
        * @return returns true if m_top is null, false otherwise
        **/
	virtual bool isEmpty() const = 0;

};
#endif