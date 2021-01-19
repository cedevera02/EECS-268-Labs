/*
*File name: ReadMaze.cpp
*Author: Carlos De Vera
*KU ID: 2925639
*Assignment: EECS268 Lab #7
*Date: 10/21/2020
*/

#include "ReadMaze.h"

ReadMaze::ReadMaze(std::string file)
{
    m_row = 0;
    m_col=0;
    read(file);
}

int ReadMaze::getRow() const
{
    return (m_row);
}

int ReadMaze::getCol() const
{
    return (m_col);
}

int ReadMaze::getStartRow() const
{
    return (m_startR);
}

int ReadMaze::getStartCol() const
{
    return (m_startC);
}

void ReadMaze::read(std::string file)
{
    std::ifstream input;
    int numIn;
    char varIn;
    input.open(file);
    if (input.is_open())
    {
        input >> numIn;
        m_row = numIn;
        input >> numIn;
        m_col = numIn;
        input >> numIn;
        m_startR = numIn;
        input >> numIn;
        m_startC = numIn;
        validParameters();

        m_maze = new char*[m_row];
        for (int i = 0; i < m_row; i++)
        {
            m_maze[i] = new char[m_col];
        }

        for (int i = 0; i < m_row; i++)
        {
            for (int j = 0; j < m_col; j++)
            {
                input >> varIn;
                m_maze[i][j] = varIn;
            }
        }

        if (m_maze[m_startR][m_startC] == 'W')
        {
            std::cout << "ERROR: Start position is invalid\n";
            exit(1);
        }
    }
    else
    {
        std::cout << "ERROR: File cannot be opened\n";
        exit(1);
    }
}

void ReadMaze::validParameters()
{
    if (m_row <=0)
    {
        std::cout << "ERROR: Invalid Row\n";
        exit(1);
    }
    if (m_col <=0)
    {
        std::cout << "ERROR: Invalid Column\n";
        exit(1);
    }
    if (m_startR <0 || m_startR >= m_row)
    {
        std::cout << "ERROR: Start Row is not within range\n";
        exit(1);
    }
    if (m_startC <0 || m_startC >= m_col)
    {
        std::cout << "ERROR: Start Column is not within range\n";
        exit(1);
    }
}

void ReadMaze::getMaze(char *maze[]) const
{
    for (int i = 0; i < m_row; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
            maze[i][j] = m_maze[i][j];
        }
    }
}

void ReadMaze::printMaze()
{
    for (int i = 0; i < m_row; i ++)
    {
        for (int j = 0; j < m_col; j++)
        {
            std::cout << m_maze[i][j];
        }
        std::cout << "\n";
    }
}