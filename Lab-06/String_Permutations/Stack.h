/*
File name: Stack.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #6
Date: 10/14/2020
*/

#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>
class Stack
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
        * @pre Stack is non-empty
        * @post makes no changes
        * @return returns the values stored in Node index from top
        * @param index position wanted to be checked
        * @throw if m_top is null, throws a runtime error
        **/
	T peek(int index) const;

       /**
        * @post makes no changes 
        * @return returns true if m_top is null, false otherwise
        **/
	bool isEmpty() const;

       /**
        * @pre none
        * @post counts how many Nodes are in the Stack
        * @return number of Nodes in Stack
        **/
       int numOfN();

};

#include "Stack.cpp"
#endif