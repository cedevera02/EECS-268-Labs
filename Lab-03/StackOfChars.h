/*
File name: StackOfChars.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #3
Date: 9/16/2020
*/

#ifndef STACKOFCHARS_H
#define STACKOFCHARS_H

#include "Node.h"

class StackOfChars
{
	private:
	Node* m_top;
	
	public:
	
	StackOfChars();

	StackOfChars(const StackOfChars& orig);

       ~StackOfChars();

	void operator=(const StackOfChars& rhs);
	
       /** Here's an example of a doxygen comment block. Do this for all methods
       * @pre None
       * @post entry is added to top of the stack
       * @param entry, the element to be added to the stack
       * @throw None
       **/
	void push(char entry);
	
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
	char peek() const;

       /**
        * @post makes no changes 
        * @return returns true if m_top is null, false otherwise
        **/
	bool isEmpty() const;

};
#endif