/*
File name: StackOfChars.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #3
Date: 9/16/2020
*/

#include "StackTester.h"
#include <iostream>

StackTester::StackTester()
{
    runTests();
}

void StackTester::runTests()
{
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    test08();
    test09();
    test10();
    test11();
    test12();
    test13();
    test14();
}

void StackTester::test01()
{
    StackOfChars stack;

    std::cout <<"Test 01: New stack is empty: ";

    if (stack.isEmpty())
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }
    
}

void StackTester::test02()
{
    StackOfChars stack;

    std::cout <<"Test 02: Push on empty stack makes it non-empty: ";
    stack.push('A');

    if (stack.isEmpty())
    {
        std::cout << "FAILED\n";
    }
    else
    {
        std::cout << "PASSED\n";
    }
}

void StackTester::test03()
{
    StackOfChars stack;

    std::cout <<"Test 03: Popping all elements makes stack empty: ";
    stack.push('A');

    try
    {
        stack.pop();
        if (stack.isEmpty())
        {
            std::cout << "PASSED\n";
        }
        else
        {
            std::cout << "FAILED\n" ;
        }
    }
    catch(std::runtime_error& rte)
    {
        std::cout << "FAILED!\n";
    }
}

void StackTester::test04()
{
    StackOfChars stack;

    std::cout <<"Test 04: Popping all elements makes stack empty: ";
    stack.push('A');
    stack.push('B');
    stack.push('C');
    try
    {
        stack.pop();
        stack.pop();
        stack.pop();
        if (stack.isEmpty())
        {
            std::cout << "PASSED\n";
        }
        else
        {
            std::cout << "FAILED\n" ;
        }
    }
    catch(std::runtime_error& rte)
    {
        std::cout << "FAILED!\n";
    }
}

void StackTester::test05()
{
    StackOfChars stack;

    std::cout <<"Test 05: Popping only 2/3 elements means stack is not empty: ";
    stack.push('A');
    stack.push('B');
    stack.push('C');
    try
    {
        stack.pop();
        stack.pop();
        if (stack.isEmpty())
        {
            std::cout << "FAILED\n";
        }
        else
        {
            std::cout << "PASSED\n" ;
        }
    }
    catch(std::runtime_error& rte)
    {
        std::cout << "FAILED!\n";
    }
}

void StackTester::test06()
{
    StackOfChars stack;

    std::cout <<"Test 06: Popping an empty stack: ";

    try
    {
        stack.pop();
        std::cout << "FAILED\n" ;
    }
    catch(std::runtime_error& rte)
    {
        std::cout << "PASSED\n";
    }
}

void StackTester::test07()
{
    StackOfChars stack;

    std::cout <<"Test 07: Pushed elements are in opposite order of push: ";
    stack.push('A');
    stack.push('B');
    try
    {
        if (stack.peek()=='B')
        {
            std::cout << "PASSED\n";
        }
        else
        {
            std::cout << "FAILED\n";
        }
    }
    catch(std::runtime_error& rte)
    {
        std::cout << "FAILED!\n";
    }
}

void StackTester::test08()
{
    StackOfChars stack;

    std::cout <<"Test 08: Peeking into an empty stack: ";

    try
    {
        std::cout << stack.peek() << " is returned, thus: FAILED\n";
    }
    catch(std::runtime_error& rte)
    {
        std::cout << "PASSED\n";
    }
}

void StackTester::test09()
{
    StackOfChars stack;

    std::cout <<"Test 09: Setting one stack equal to another at declaration: ";
    stack.push('A');
    stack.push('B');
    stack.push('C');
    
    StackOfChars stackCopy(stack);
    try
    {
        if(stack.peek()==stackCopy.peek())
        {
            stack.pop();
            stackCopy.pop();
            if(stack.peek()==stackCopy.peek())
            {
                stack.pop();
                stackCopy.pop();
                if (stack.peek()==stack.peek())
                {
                    std::cout << "PASSED\n";
                }
                else
                {
                    std::cout << "FAILED\n";
                }
            }
            else
            {
                std::cout << "FAILED\n";
            }
        }
        else
        {
            std::cout << "FAILED\n";
        }

    }
    catch (std::runtime_error& rte)
    {
        std::cout << "FAILED\n";
    }
}

void StackTester::test10()
{
    StackOfChars stack;

    std::cout <<"Test 10: Deep Copy of one stack to another at declaration: ";
    stack.push('A');
    stack.push('B');
    stack.push('C');
    
    StackOfChars stackCopy(stack);

    stack.pop();
    stack.pop();
    stack.pop();
    try
    {
        if(stackCopy.peek()=='C')
        {
            stackCopy.pop();
            if(stackCopy.peek()=='B')
            {
                stackCopy.pop();
                if (stackCopy.peek()=='A')
                {
                    std::cout << "PASSED\n";
                }
                else
                {
                    std::cout << "FAILED\n";
                }
            }
            else
            {
                std::cout << "FAILED\n";
            }
        }
        else
        {
            std::cout << "FAILED\n";
        }

    }
    catch (std::runtime_error& rte)
    {
        std::cout << "FAILED\n";
    }
}

void StackTester::test11()
{
    StackOfChars stack;

    std::cout <<"Test 11: Setting one stack equal to another after declaration: ";
    stack.push('A');
    stack.push('B');
    stack.push('C');
    
    StackOfChars stackCopy;
    stackCopy = stack;
    try
    {
        if(stack.peek()==stackCopy.peek())
        {
            stack.pop();
            stackCopy.pop();
            if(stack.peek()==stackCopy.peek())
            {
                stack.pop();
                stackCopy.pop();
                if (stack.peek()==stack.peek())
                {
                    std::cout << "PASSED\n";
                }
                else
                {
                    std::cout << "FAILED\n";
                }
            }
            else
            {
                std::cout << "FAILED\n";
            }
        }
        else
        {
            std::cout << "FAILED\n";
        }

    }
    catch (std::runtime_error& rte)
    {
        std::cout << "FAILED\n";
    }
}

void StackTester::test12()
{
    StackOfChars stack;

    std::cout <<"Test 12: Deep Copy of one stack to another at declaration: ";
    stack.push('A');
    stack.push('B');
    stack.push('C');
    
    StackOfChars stackCopy(stack);

    stack.pop();
    stack.pop();
    stack.pop();
    try
    {
        if(stackCopy.peek()=='C')
        {
            stackCopy.pop();
            if(stackCopy.peek()=='B')
            {
                stackCopy.pop();
                if (stackCopy.peek()=='A')
                {
                    std::cout << "PASSED\n";
                }
                else
                {
                    std::cout << "FAILED\n";
                }
            }
            else
            {
                std::cout << "FAILED\n";
            }
        }
        else
        {
            std::cout << "FAILED\n";
        }

    }
    catch (std::runtime_error& rte)
    {
        std::cout << "FAILED\n";
    }
}

void StackTester::test13()
{
    StackOfChars stack;
    StackOfChars stackCopy(stack);
    std::cout << "Test 13: Copy at declaration works with empty stack: ";
    if (stackCopy.isEmpty())
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }
}

void StackTester::test14()
{
    StackOfChars stack;
    StackOfChars stackCopy;
    stackCopy = stack;
    std::cout << "Test 14: Copy after declaration works with empty stack: ";
    if (stackCopy.isEmpty())
    {
        std::cout << "PASSED\n";
    }
    else
    {
        std::cout << "FAILED\n";
    }
}