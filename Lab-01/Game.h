/*
File name: Game.h
Author: Carlos Emil De Vera
KU ID: 2925639
Assignment: EECS268 Lab #1
Date: 9/5/2020
*/

#ifndef GAME_H
#define GAME_H
#include <iostream>

class Game
{
    private:
    std::string m_Name;
    double m_GR, m_PR, m_MT;
    int m_Year, m_MP;

    public:

    Game();
    //@pre - a Game instance must be created
    //@post - all private member variables will be intitialized with 0 or "" for strings

    void setName(std::string name);
    //@pre-takes in a string that will set the Name of the Game object
    //@post-takes the name of the passed in value and sets it on the m_gameName variable

    void setGR(double gRate);
    //@pre- requires a double to take in and set as the Gibbons Rating
    //@post - sets the passed in double into m_GR

    void setPR(double pRate);
    //@pre - takes in a double value and sets it as the Public Rating
    //@post - sets the passed in double into m_PR

    void setMT(double time);
    //@pre- takes in a double value and sets it as the Minimum Play Time
    //@post - sets the passed in value as the m_MT

    void setYear (int year);
    //@pre - takes in a int value and sets it as the Year of the Game
    //@post - sets the passed in value and sets it as m_Year

    void setMP (int people);
    //@pre - takes in an int value and sets it as the Minimum Number of Players
    //@post - sets the passed in int value as m_MP

    std::string getName();
    //@pre- the m_Name must have a string stored in it in order to be displayed
    //@post - the method does not change the variable
    //@returns the string stored in m_Name will be returned

    double getGR();
    //@pre- the m_GR variable must have a valid double stored
    //@post - does not make any changes to the m_GR variable
    //@returns the double stored in m_GR

    double getPR();
    //@pre - the m_PR must have a valid double stored
    //@post - does not make any changes to the m_PR variabe
    //@returns the double stored in m_PR

    double getMT();
    //@pre- the m_MT must have a valid double stored
    //@post - does not make any changes to the m_MT variable
    //@returns the double stored in m_MT

    int getYear ();
    //@pre - the variable m_Year must have a valid int stored
    //@post - does not make any changes to the m_Year variable
    //@returns the int stored in m_Year

    int getMP ();
    //@pre - the variable m_MP must have a valid int stored
    //@post - does not make any changes to the m_MP variable
    //@returns the int stored in m_MP


};
#endif