/*
*File name: MazeWalker.cpp
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #7
*Date: 10/21/2020
*/

#include "MazeWalker.h"

MazeWalker::MazeWalker(std::string file)
{
    m_reader = new ReadMaze(file);
    m_col = m_reader->getCol();
    m_row = m_reader->getRow();
    m_maze = new char*[m_row];
    for (int i = 0; i < m_row; i++)
    {
        m_maze[i] = new char[m_col];
    }
    m_numSteps = 0;
    m_reader->getMaze(m_maze);
    defineIntMaze();

}

void MazeWalker::defineIntMaze()
{
    m_visited = new int*[m_row];
    for (int i = 0; i < m_row; i++)
    {
        m_visited[i] = new int[m_col];
    }

    for (int i = 0; i < m_row; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
            m_visited[i][j] = 0;
        }
    }
}

void MazeWalker::markMaze(int row, int col)
{
    m_numSteps++;
    m_visited[row][col] = m_numSteps;
}

void MazeWalker::unmarkMaze(int row, int col)
{
    m_numSteps--;
    m_visited[row][col] = 0;
}

bool MazeWalker::isValid(int row, int col)
{
    bool valid = false;
    if (row < m_row && row >= 0)
    {
        if (col < m_col && col >= 0)
        {
            if (m_maze[row][col] !='W' && m_visited[row][col]==0)
            {
                valid = true;
            }
        }
    }
    return valid;
}

bool MazeWalker::walkMaze(int row, int col)
{
    markMaze(row, col);
    if (m_maze[row][col]=='E')
    {
        return true;
    }
    //moves in order up,right,left,down
    if (isValid(row-1,col))
    {
        if (walkMaze(row-1,col))
        {
            return true;
        }
    }
    if (isValid(row,col+1))
    {
        if (walkMaze(row,col+1))
        {
            return true;
        }
    }
    if (isValid(row+1,col))
    {
        if (walkMaze(row+1,col))
        {
            return true;
        }
    }
    if (isValid(row,col-1))
    {
        if (walkMaze(row,col-1))
        {
            return true;
        }
    }
    unmarkMaze(row,col);
    return false;
}

void MazeWalker::solveMaze()
{
    int startR = m_reader->getStartRow();
    int startC = m_reader->getStartCol();
    if (walkMaze(startR,startC))
    {
        std::cout <<"\nStarting Position: " << startR << ", " << startC << "\n";
        std::cout << "Size: " << m_row << ", " << m_col << "\n";
        printSolution();
        std::cout << "We escaped!\n";
    }
    else
    {
        std::cout <<"\nStarting Position: " << startR << ", " << startC << "\n";
        std::cout << "Size: " << m_row << ", " << m_col << "\n";
        std::cout << "No way out!\n";
    }
    
}

void MazeWalker::printSolution()
{
    std::cout << "\n\nVisited:\n";
    for (int i = 0; i < m_row; i ++)
    {
        for (int j = 0; j < m_col; j++)
        {
            if (m_visited[i][j] < 10)
            {
                std::cout << m_visited[i][j] << "     ";
            }
            else
            {
                std::cout << m_visited[i][j] << "    ";
            }
        }
        std::cout << "\n";
    }
}