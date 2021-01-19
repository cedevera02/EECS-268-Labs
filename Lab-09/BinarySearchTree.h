/*
File name: BinarySearchTree.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #5
Date: 10/3/2020
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYDEARCHTREE_H

#include "BinarySearchTreeInterface.h"
#include "BinaryNode.h"
#include <stdexcept>
#include <iostream>

template <typename ItemType, typename KeyType>
class BinarySearchTree: public BinarySearchTreeInterface<ItemType,KeyType>
{
    private:

    BinaryNode<ItemType>* m_root;

    /**
     * @brief recursively treaverses the BST and adds the entry at correct position
     * @param entry to be added into BST
     * @param subtree points to current subtree the method is looking at
     * @throw throws an runtime error if entry is already present in BST
     */
    void recAdd(ItemType entry, BinaryNode<ItemType>* subtree);

    /**
     * @brief recursively seraches for key in BST
     * @param key value that will be used to check if an ItemType with value key is in BST
     * @param subtree position of current BNode that is being checked
     * @return ItemType of the BinaryNode holding key value
     * @throw runtime error if key is not in BST
     */
    ItemType recSearch(KeyType key, BinaryNode<ItemType>* subtree) const;

    /**
     * @brief recursively traverses the tree in postorder and deletes each BNode
     * @param subtree current BNode being looked at
     */
    void recClear(BinaryNode<ItemType>* subtree);

    /**
     *@brief resursively traverses the BST starting from the very bottom
     *@param subtree current subtree being looked at
     *@param visit method used to determin what type of visit will be done
     */
    void visitPost(void visit(ItemType), BinaryNode<ItemType>* subtree) const;

    /**
     *@brief resursively traverses the BST starting from the very top
     *@param subtree current subtree being looked at
     *@param visit method used to determin what type of visit will be done
     */
    void visitPre(void visit(ItemType), BinaryNode<ItemType>* subtree) const;

    /**
     *@brief resursively traverses the BST in order
     *@param subtree current subtree being looked at
     *@param visit method used to determin what type of visit will be done
     */
    void visitIn(void visit(ItemType), BinaryNode<ItemType>* subtree) const;

    /**
     * @brief recursively traverses the passed in tree in pre order and adds each entry to this tree
     * @pre if a true copy is wanted, this tree must be empty
     * @param subtree current subtree being looked at
     **/
    void copy(BinaryNode<ItemType>* subtree);

    /**
     * @brief finds the BNode that contains the key and calls removeHelper
     * @param key value being removed
     * @param prevSubtree parent Node of currSubtree
     * @param currSubstree current subtree being looked at
     * @param direction indicates whether the previous call went left or right or if it is looking at the root
     * @throw throws runtime error if key is not in tree
     **/
    void removeFinder(KeyType key, BinaryNode<ItemType>* prevSubtree, BinaryNode<ItemType>* currSubtree, char direction);

    /**
     * @brief figures out the correct decision of removal based on how many children the BNode has
     * @param prevSubtree parent Node of currSubtree
     * @param currSubstree current subtree being looked at
     * @param direction indicates whether the previous call went left or right or if it is looking at the root
     * @return pointer to Node that contains key
     **/
    BinaryNode<ItemType>* removeHelper(BinaryNode<ItemType>* prevSubtree, BinaryNode<ItemType>* currSubtree, char direction);

    /**
     * @brief goes to the left most Node in the right subtree of prevSubtree
     * @param prevSubtree parent Node of currSubtree
     * @param currSubstree current subtree being looked at
     * @return pointer to Node that contains leftmost Node
     **/
    BinaryNode<ItemType>* leftMostFinder(BinaryNode<ItemType>* prevSubtree, BinaryNode<ItemType>* currSubtree);


    public:

    /**
     * @brief searches for target by calling booleanRecSearch
     * @return true if target is in tree, false if not
     * @param target value being searched for
     **/
    bool booleanSearch(KeyType target) const;

    /**
     * @brief recursively searches for target
     * @return true if target is in tree, false if not
     * @param target value being searched for
     * @param subtree current subtree being looked at
     **/
    bool booleanRecSearch(KeyType target, BinaryNode<ItemType>* subtree) const;

    BinarySearchTree();

    /**
     * @brief makes a deep copy of contents of tree
     * @param tree BST that will be copied into this tree
     **/
    BinarySearchTree(BinarySearchTree<ItemType,KeyType>* tree);

    ~BinarySearchTree();

    /**
     * @brief returns pointer to m_root
     **/
    BinaryNode<ItemType>* getRoot();
    
    void add(ItemType entry); //throws std::runtime_error if duplicate added

    /**
     * @brief calls recSearch
     * @param key value that will be used to see if there exists an ItemType with the key variable
     * @throw runtime error if key is not in BST
     */
    ItemType search(KeyType key) const;

    /**
     * @brief empties the tree
     */
    void clear();

    void remove(KeyType key); //throws std::runtime_error if not in tree

    //For the following methods, each method will take a function as a parameter
    //These function then call the provided function on every entry in the tree in the appropriate order (i.e. pre, in, post)
    //The function you pass in will need to a static method
    void visitPreOrder(void visit(ItemType)) const; //Visits each node in pre order
    void visitInOrder(void visit(ItemType)) const; //Visits each node in in order
    void visitPostOrder(void visit(ItemType)) const; //Visits each node in post order


};

#include "BinarySearchTree.cpp"
#endif