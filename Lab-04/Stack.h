/*
File name: Stack.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include "StackInterface.h"

template <typename T>
class Stack: public StackInterface<T>
{
	private:
	Node<T>* m_top;
	
	public:
	
	Stack();

	Stack(const Stack<T>& orig);

       ~Stack();

	void operator=(const Stack<T>& rhs);
	
       /**
       * @pre None
       * @post entry is added to top of the stack
       * @param entry, the element to be added to the stack
       * @throw None
       **/
	void push(T entry);
	
       /** Here's an example of a doxygen comment block. Do this for all methods
       * @pre Stack is non-empty
       * @post Top element is removed from the stack
       * @param None
       * @throw std::runtime_error if pop attempted on empty stack
       **/
	void pop();
	
       /**
        * @pre Stack is non-empty
        * @post makes no changes
        * @return returns the values stored in m_top
        * @throw if m_top is null, throws a runtime error
        **/
	T peek() const;

       /**
        * @post makes no changes 
        * @return returns true if m_top is null, false otherwise
        **/
	bool isEmpty() const;

};

#include "Stack.cpp"
#endif