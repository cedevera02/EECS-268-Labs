/*
File name: Permutations.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #6
Date: 10/14/2020
*/

#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include <iostream>
#include <string>
#include "Stack.h"

class Permutations
{
    private:
    Stack<std::string> wordStack;
    int numOfPerm;
    public:


    /**
     * @pre none
     * @post calculates factorial of given num
     * @param num to be calculated the factorial of
     * @return value of num factorial
     */
    int factorial(int num);

    /**
     * @pre wordArr must be valid
     * @post checks if word is in wordArr
     * @param word to be checked if it is in wordArr
     * @returns true if word is in wordArr false otherwise
     */
    bool present(std::string word);

    /**
     * @post calls allPerm and sets word as parameter,finds length of word and sets it as
     * second parameter
     * @param word to be found all possible permutations of
     */
    Permutations(std::string word);

    /**
     * @pre none
     * @post swaps two elements of the in word with each other
     * @param word string object to switch elements in
     * @param pos1 1st index wanting to be switched
     * @param pos2 2nd index wanting to be switched
     * @returns returns word with two elements swapped
     */
    std::string swap(std::string word, int pos1, int pos2);

    /**
     * @pre none
     * @post prints out all possible permutations of a string
     * @param word string object to find all posible permutations of
     * @param pos current index position to be fixed in place
     * @param length of word
     */
    void mix(std::string word, int pos, int length);

    /**
     * @pre none
     * @post prints out all possible permutations down to the letter, not just of the word
     * @param word string to be found all possible permutations of
     * @param length of word
     */
    void allPerm(std::string word, int length);
};

#endif