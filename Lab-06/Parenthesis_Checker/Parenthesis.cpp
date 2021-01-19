/*
File name: Parenthesis.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #6
Date: 10/14/2020
*/

#include "Parenthesis.h"

Parenthesis::Parenthesis(std::string word)
{
    run(word);
}

bool Parenthesis::parensChecker(std::string word)
{
    if (word.length() <= 2)
    {
        if (word == "()")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (word[0] == '(')
        {
            int length = word.length();
            for (int i =1; i < length; i++)
            {
                if (word[i] ==')')
                {
                    word.erase(word.begin()+i);
                    break;
                }
            }
            word.erase(word.begin());
            return(parensChecker(word));
        }
        else if (word[0] ==')')
        {
            return false;
        }
        else
        {
            return false;
        }
        
    }
}

void Parenthesis::run(std::string word)
{

    if (!impureString(word))
    {
        bool balanced = false;
        balanced =  parensChecker(word);
        if (balanced)
        {
            std::cout << "The sequence " << word << " is balanced\n";
        }
        else
        {
            std::cout << "The sequence " << word << " is not balanced\n";
        } 
    }
    else
    {
        std::cout << "ERROR: Invalid character in input\n";
        exit(1);
    }
    
}

bool Parenthesis::impureString(std::string word)
{
    bool check = false;
    int length = word.length();
    for (int i = 0; i <length; i++)
    {
        if (word[i] != '(' && word[i] != ')')
        {
            check = true;
        }
    }
    return (check);
}