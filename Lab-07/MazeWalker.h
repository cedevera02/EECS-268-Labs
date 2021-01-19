/*
*File name: MazeWalker.h
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #7
*Date: 10/21/2020
*/

#ifndef MAZEWALKER_H
#define MAZEWALKER_H

#include <iostream>
#include "ReadMaze.h"

class MazeWalker
{
    private:
    ReadMaze* m_reader;
    char ** m_maze;
    int** m_visited;
    int m_numSteps;
    int m_col;
    int m_row;

    /**
     * @pre m_row and m_col must be defined based on the maze's row and col
     * @post intitializes m_visited based on m_row and m_col
     */
    void defineIntMaze();

    /**
     * @pre m_maze must have valid maze
     * @post moves to parameter's row and col, increments the num of steps and marks where on m_visited
     * @param row location of which row to go
     * @param col location of which column to go
     * @return true if move is posiible, false otherwise
     */
    bool walkMaze(int row, int col);

    /**
     * @pre must be a valid m_visited defined
     * @post increments m_numSteps by 1 and sets position row by col in m_visited by m_numSteps
     * @param row row where marking will occur
     * @param col col where marking will occur
     */
    void markMaze(int row, int col);

    /**
     * @pre must be a valid m_visited defined
     * @post decrements m_numSteps by 1 and sets position row by col in m_visited to 0
     * @param row row where unmarking will occur
     * @param col col where unmarking will occur
     */
    void unmarkMaze(int row, int col);

    /**
     * @pre all member variable must have valid values (i.e. m_row, m_col, and m_maze)
     * @post checks whether next move prompted by parameter is valid
     * @param row row to move into
     * @param col col to move into
     * @return true if move is valid, false if not
     */
    bool isValid(int row, int col);

    /**
     * @pre walkMaze must have run succesfully
     * @post prints out m_visited
     */
    void printSolution();

    public:

    /**
     * @brief initialize all private members with file's contents
     * @param file name of file to be read into m_reader
     */
    MazeWalker(std::string file);

    /**
     * @pre all member variables must be initialized with valid values
     * @post calls needed functions to solve maze and outputs the results
     */
    void solveMaze();
};

#endif