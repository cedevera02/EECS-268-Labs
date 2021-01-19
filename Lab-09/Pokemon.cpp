/*
File name: Pokemon.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #9
Date: 11/11/2020
*/

#include "Pokemon.h"

Pokemon::Pokemon()
{
    m_pokedexNumber = 0;
    m_JapaneseName = "";
    m_AmericanName = "";
}

void Pokemon::setAmName(std::string name)
{
    m_AmericanName = name;
}

void Pokemon::setJapName(std::string name)
{
    m_JapaneseName = name;
}

void Pokemon::setPokedex(int pokedex)
{
    m_pokedexNumber = pokedex;
}

int Pokemon::getPokedex() const
{
    return m_pokedexNumber;
}

std::string Pokemon::getAmName() const
{
    return m_AmericanName;
}

std::string Pokemon::getJapName() const
{
    return m_JapaneseName;
}

bool Pokemon::operator>(const Pokemon& rhs) const
{
    if (m_pokedexNumber > rhs.getPokedex())
    {
        return true;
    }
    else
    {
        return false;
    }  
}

bool Pokemon::operator==(const Pokemon& rhs) const
{
    if (m_pokedexNumber == rhs.getPokedex())
    {
        return true;
    }
    else
    {
        return false;
    }  
}

bool Pokemon::operator==(int rhs) const
{
    if (m_pokedexNumber == rhs)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Pokemon::operator>(int rhs) const
{
    if (m_pokedexNumber > rhs)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Pokemon::print(Pokemon monster)
{
    std::cout << monster.getAmName() << '\t';
    std::cout << monster.getPokedex() << '\t';
    std::cout << monster.getJapName() << '\n';
}