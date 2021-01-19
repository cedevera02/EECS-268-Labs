/*
*File name: ReadMaze.h
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #7
*Date: 10/21/2020
*/

#ifndef READMAZE_H
#define READMAZE_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class ReadMaze
{
    private:
    int m_row;
    int m_col;
    int m_startR;
    int m_startC;
    char **m_maze;

    public:
    
    /**
     * @pre none
     * @post sets row and col to 0, calls read with file as parameter
     * @param file name of file that will be input into read()
     */
    ReadMaze(std::string file);

    /**
     * @pre m_row, m_col, m_startR, m_startC must have valid values
     * @post checks if m_row, m_col, m_startR, m_startC are valid
     * 
     */
    void validParameters();

    /**
     * @pre m_row must have valid value
     * @post makes no changes to m_row
     * @return returns m_row
     */
    int getRow() const;

    /**
     * @pre m_col must have valid value
     * @post makes no changes to m_col
     * @return returns m_col
     */
    int getCol() const;

    /**
     * @pre m_row must have valid value
     * @post makes no changes to m_StartR
     * @return returns m_startR
     */
    int getStartRow() const;

    /**
     * @pre m_col must have valid value
     * @post makes no changes to m_StartC
     * @return returns m_startC
     */
    int getStartCol() const;

    /**
     * @pre none
     * @post sets col, row, and m_maze based off of info from file, if invalid it ends program
     * @param file name of file to be read in
     */
    void read(std::string file);

    /**
     * @pre all private member variables must have valid values
     * @post prints out maze
     */
    void printMaze();

    /**
     * @pre m_maze must have valid 2d array of chars
     * @post sets input aray with identical maze as m_maze
     * @param maze to be set the same as m_maze
     * @param col number of col the maze has
     */
    void getMaze(char *maze[]) const;

};

#endif