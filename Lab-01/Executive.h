/*
File name: Executive.h
Author: Carlos Emil De Vera
KU ID: 2925639
Assignment: EECS268 Lab #1
Date: 9/5/2020
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include "Game.h"

class Executive
{
    private:

    std::string m_FileIn;
    int m_numGames, m_UserChoice;
    Game* m_newGames;

    public:

    Executive(std::string file);
    //@pre - no requirements
    //@post - stores the passed in string into the m_FileIn variable

    ~Executive();
    //@pre - must be finished with the program
    //@post - deletes everything in the heap

    void run();
    //@pre - Executive instance must be created and member variables must have valid values
    //@post - runs the program, allowing the user to choose what action they would like to be performed

    void printMenu();
    //@pre - no requirements
    //@post - prints the Menu of choices for actions that the user can choose from

    void createGames();
    //@pre - m_FileIn must have a valid file name to read in from in order to create Game instances
    //@post - creates as many Game objects as is listed in the file, stores how many games created in m_numGames
    //and stores the array of games in m_newGames

    void printGame(Game object);
    //@pre - needs a Game object passed into with valid member variables
    //@post - prints out the information stored in the Game object

    void findYear();
    //@pre - m_newGames must store Game instance(s)
    //@post - prompts user for year, then prints out the games that are in the specifed year or "No games found" if there are none

    void rankRange();
    //@pre - m_newGames must store Game instance(s)
    //@post - gets a range from the user (1-10) and prints out the games that have their m_GR in between range

    void peopleVGibbons();
    //@pre - m_newGames must store Game instance(s)
    //@post - gets a double from user (0-10) then prints out which games have a difference of the given value
    //between the m_PR and the m_GR or more

    void playTime();
    //@pre - m_newGames must store Game instance(s)
    //@post - prompts user for a time then displays the games with that minimum play time or lower

    double abs(double input);
    //@pre - must be passed in a double value
    //@post - takes the absolute value of the passed in value
    //@returns - returns the value passed in as an absolute value

    void border();
    //@pre - no requirements
    //@post - prints out a border of asterisks




    

};

#endif