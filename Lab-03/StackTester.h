/*
File name: StackTester.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #3
Date: 9/16/2020
*/

#ifndef STACKTESTER_H
#define STACKTESTER_H

#include "StackOfChars.h"

class StackTester
{
    public: 

    StackTester();

    //This will call all your test methods
    void runTests();
     
    private:

    /**
    * @brief Creates an empty stack and verifies isEmpty() returns true
    **/
    void test01();

    /**
    * @brief Creates an empty stack pushes 1 value, verifies isEmpty() returns false
    **/
    void test02();

    /**
    * @brief Creates an empty stack, then pushes once, pops once, and verifies isEmpty returns true
    **/
    void test03();

    /**
    * @brief Creates an empty stack, then pushes three times, pops three times, and verifies isEmpty returns true
    **/
    void test04();

    /**
    * @brief Creates an empty stack, then pushes three times, pops two times, and verifies isEmpty returns false
    **/
    void test05();

    /**
    * @brief Creates an empty stack, pops, verifies a runtime error is thrown
    **/
    void test06();

    /**
    * @brief Creates an empty stack, pushes two values and then verifies the order is correct
    * (i.e. the most recent push is at the top, this also verifies that push is working)
    **/
    void test07();

    /**
    * @brief Creates an empty stack, peeks and then verifies a runtime error was thrown
    **/
    void test08();

    /**
    * @brief Creates a stack and fills it with values then creates another stack and sets the first
    * as a paramter for the copy constructor. Checks if the second stack has the same values
    **/
    void test09();

    /**
    * @brief Creates a stack and fills it with values then creates another stack and sets the first
    * as a paramter for the copy constructor. Deletes the original to checks the second stack 
    * is deep copied
    **/
    void test10();

    /**
    * @brief Creates a stack and fills it with values then creates another stack and sets the first
    * equal to it after declaration. Checks if the second stack has the same values
    **/
    void test11();

    /**
    * @brief Creates a stack and fills it with values then creates another stack and sets the first
    * equal to it after declaration. Deletes the original to checks the second stack 
    * is deep copied
    **/
    void test12();

    /**
    * @brief Creates an empty stack then creates another stack and sets the first
    * equal to it at declaration(should return true when isEmpty is called)
    **/
    void test13();

    /**
    * @brief Creates an empty stack then creates another stack and sets the first
    * equal to it after declaration (should return true when isEmpty is called)
    **/
    void test14();
};

#endif