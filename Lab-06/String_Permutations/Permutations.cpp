/*
File name: Permutations.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #6
Date: 10/14/2020
*/

#include "Permutations.h"

Permutations::Permutations(std::string word)
{
    int length = word.length();

    numOfPerm = 0;
    for (int i = 1; i <= length; i++)
    {
        numOfPerm = numOfPerm + factorial(i);
    }
    
    allPerm(word,length);
}


int Permutations::factorial(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    else
    {
        return (num*factorial(num-1));
    }
}

bool Permutations::present(std::string word)
{
    for (int i = 0; i < wordStack.numOfN(); i++)
    {
        if (wordStack.peek(i) == word)
        {
            return true;
        }
    }
    return false;
}

std::string Permutations::swap(std::string word, int pos1, int pos2)
{
    char temp = word[pos1];
    word[pos1] = word[pos2];
    word[pos2] = temp;

    return word;
}

void Permutations::mix(std::string word, int pos, int length)
{
    if (pos == (length-1))
    {
        std::cout << word << '\n';
    }
    else
    {
        for (int i = pos; i < length; i++)
        {
            word = swap(word,pos,i);
            mix(word,pos+1,length);
            word = swap(word,pos,i);
        }
    }
}

void Permutations::allPerm(std::string word, int length)
{
    if (length==1)
    {
        if (!present(word))
        {
            wordStack.push(word);
            std::cout << word << '\n';
        }
    }
    else
    {
        mix(word,0,length);
        for(int i = 0; i < length; i++)
        {
            std::string temp = word;
            temp.erase(temp.begin()+i);
            allPerm(temp,length-1);
        }
    }
    
}