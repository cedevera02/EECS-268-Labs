/*
File name: Node.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#ifndef NODE_H
#define NODE_H

#include "myException.h"

template <typename T>
class Node
{
	private:
	T m_entry;
	Node<T>* m_next;
	
	public:
	Node(T entry);
	//@post - sets entry to m_entry and sets m_next to null

	T getEntry() const;
	//@pre - m_entry must have valid T stored
	//@post - does not change m_entry
	//@return - returns the value in m_entry

	void setEntry(T entry);
	//@post - sets entry into m_entry
	//@param - entry is the T to be added into m_entry

	Node<T>* getNext() const;
	//@pre - m_next must have a valid Node stored
	//@post - makes no changes
	//@return - returns the Node stored in m_next

	void setNext(Node<T>* next);
	//@post - sets next as m_next
	//@param - next is the Node to be placed into m_next

};

#include "Node.cpp"
#endif