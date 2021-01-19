/*
File name: Pokemon.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #9
Date: 11/11/2020
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>

class Pokemon
{
    private:

    std::string m_AmericanName;
    std::string m_JapaneseName;
    int m_pokedexNumber;

    public:

    Pokemon();
    
    /**
     * @brief sets m_AmericanName with passed in name
     * @param name to be set to m_AmericanName
     */
    void setAmName(std::string name);

    /**
     * @brief sets m_JapaneseName with passed in name
     * @param name to be set to m_JapaneseName
     */
    void setJapName(std::string name);

    /**
     * @brief sets m_pokedexNumber with passed in pokedex
     * @param pokedex to be set to m_pokedexNumber
     */
    void setPokedex(int pokedex);

    /**
     * @brief makes no changes to m_pokedecNumber
     * @return returns m_pokedexNumber
     */
    int getPokedex() const;

    /**
     * @brief makes no changes to m_AmericanName
     * @return returns m_AmericanName
     */
    std::string getAmName() const;

    /**
     * @brief makes no changes to m_JapansesName
     * @return returns m_JapanesenName
     */
    std::string getJapName() const;

    /**
     * @brief compares this Pokemon's pokedexNumber with rhs' pokedex number
     * @param rhs Pokemon being compared with this Pokemon
     * @return true if this Pokemon's pokedex number is greater than the rhs, false otherwise
     */
    bool operator>(const Pokemon& rhs) const;

    /**
     * @brief compares this Pokemon's pokedexNumber with rhs' pokedex number
     * @param rhs Pokemon being compared with this Pokemon
     * @return true if this Pokemon's pokedex number is equal to the rhs, false otherwise
     */
    bool operator==(const Pokemon& rhs) const;

    /**
     * @brief compares this Pokemon's pokedexNumber with given pokedex number
     * @param rhs Pokedex number being compared with this Pokemon's pokedex number
     * @return true if this Pokemon's pokedex number is equal to the rhs, false otherwise
     */
    bool operator==(int rhs) const;

    /**
     * @brief compares this Pokemon's pokedexNumber with given pokedex number
     * @param rhs Pokedex number being compared with this Pokemon's pokedex number
     * @return true if this Pokemon's pokedex number is greater than the rhs, false otherwise
     */
    bool operator>(int rhs) const;

    /**
     * @brief prints out the names and pokedex of passed in Pokemon, not this Pokemon
     * @param monster pokemon's info to be printed
     */
    static void print(Pokemon monster);

};

#endif