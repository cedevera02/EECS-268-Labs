/*
File name: Executive.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #5
Date: 10/3/2020
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "BinarySearchTree.h"
#include "Pokemon.h"
#include <fstream>
#include <iostream>

class Executive
{
    private:

    BinarySearchTree<Pokemon,int>* m_tree;
    BinarySearchTree<Pokemon,int>* m_copiedTree;
    bool m_copyMade;

    public:

    Executive(std::string file);

    /**
     * @brief reads in pokemon from a file and adds them to m_tree
     * @param file name of file to read from
     */
    void readNAdd(std::string file);

    /**
     * @brief prompts the user for a task they want to perform (search, add, quit),
     *  keeps asking until user quits
     */
    void run();

    /**
     * @brief prompts a user for pokemon ID and prints out all info if present in tree
     * @param tree tree being searched
     */
    void search(BinarySearchTree<Pokemon,int>* tree);

    /**
     * @brief promts user for US and Japanese Name and pokdex # to add to m_tree
     * @param tree tree being added to
     */
    void add(BinarySearchTree<Pokemon,int>* tree);

    /**
     * @brief prompts the user if they want to print in, post, or pre order and then prints tree of choice
     * @param tree tree being printed
     */
    void printInteraction(BinarySearchTree<Pokemon,int>* tree);

    /**
     * @brief makes a deeps copy of m_tree and sets it to m_copiedTree
     **/
    void copy();

    /**
     * @brief provides user with choices and fulfills those choices based on what pokedex they chose
     * @param tree tree which the user will interact with
     **/
    void interaction(BinarySearchTree<Pokemon,int>* tree);

    /**
     *@brief prints out tree in post order
     *@param tree to be printed
     */
    void printPostTree(BinarySearchTree<Pokemon,int>* tree);

    /**
     *@brief prints out tree in pre order
     *@param tree to be printed
     */
    void printPreTree(BinarySearchTree<Pokemon,int> *tree);

    /**
     *@brief prints out tree in order
     *@param tree to be printed
     */
    void printInTree(BinarySearchTree<Pokemon,int> *tree);
};

#endif