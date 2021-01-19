/*
File name: BinaryNode.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #5
Date: 10/3/2020
*/

#ifndef BINARYNODE_H
#define BINARYNODE_H


template <typename T>
class BinaryNode
{
	private:
	T m_entry;
	BinaryNode<T>* m_left;
    BinaryNode<T>* m_right;
	
	public:
	BinaryNode(T entry);
	//@post - sets entry to m_entry and sets m_next to null

	T getEntry() const;
	//@pre - m_entry must have valid T stored
	//@post - does not change m_entry
	//@return - returns the value in m_entry

	void setEntry(T entry);
	//@post - sets entry into m_entry
	//@param - entry is the T to be added into m_entry

	BinaryNode<T>* getLeft() const;
	//@pre - m_left must have a valid Node stored
	//@post - makes no changes
	//@return - returns the Node stored in m_next

    BinaryNode<T>* getRight() const;
	//@pre - m_right must have a valid Node stored
	//@post - makes no changes
	//@return - returns the Node stored in m_next

	void setLeft(BinaryNode<T>* left);
	//@post - sets left as m_left
	//@param - next is the Node to be placed into m_next

	void setRight(BinaryNode<T>* right);
	//@post - sets left as m_left
	//@param - next is the Node to be placed into m_next
};

#include "BinaryNode.cpp"
#endif