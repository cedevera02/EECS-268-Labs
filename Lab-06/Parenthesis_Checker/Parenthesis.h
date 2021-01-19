/*
File name: Parenthesis.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #6
Date: 10/14/2020
*/

#ifndef PARENTHESIS_H
#define PARENTHESIS_H

#include <iostream>
#include <string>
#include <stdexcept>

class Parenthesis
{
    public:

    /**
     * @pre none
     * @post calls run
     * @param word to be placed into run as a parameter
     **/
    Parenthesis(std::string word);

    /**
     * @pre none
     * @post checks if word is balanced in terms of parenthesis
     * @param word to be checked
     * @return returns true if balanceed false if not
     * @throw throes runtime error if anythingg but parenthesis is input in
     **/
    bool parensChecker(std::string word);

    /**
     * @pre none
     * @post runs the methods required based on input
     * @param word word to be checked
     **/
    void run(std::string word);

    /**
     * @pre none
     * @post checks to see if word has any characters other than ( or )
     * @return false if only ( or ), true otherwise
     **/
    bool impureString(std::string word);
};

#endif