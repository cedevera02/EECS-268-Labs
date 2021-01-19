/*
File name: Elevator.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #4
Date: 9/23/2020
*/

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Queue.h"
#include "Stack.h"
#include <string>
#include <iostream>

class Elevator
{
    private:
    Queue<std::string> m_line;
    Stack<std::string> m_elevator;
    int m_numPeople;
    public:

    Elevator();

    /**
     * @pre none
     * @post places name into m_line
     * @param name is the string put into m_line
     * */
    void wait(std::string name);

    /**
     * @pre less than 7 people on the m_elevator
     * @post picks up as many names and puts them into m_elevator, dequeuing people as it goes
     * @throw runtime error is thrown if there are 7 people on m_elevator and pickUp is called
     * */
    void pickUp();

    /**
     * @pre m_elevator should have people inside
     * @post drops off as many people as specified
     * @param num is the number of people being dropped off
     * @throw runtime error is thrown if num exceeds the amount of people on the elevator
     * */
    void dropOff(int num);

    /**
     * @pre none
     * @post prints off the status of the system i.e. is the elevator emty who is next in line, and 
     * who is next to get off
     * */
    void inspection();

};

#endif