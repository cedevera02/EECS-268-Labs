/*
File name: Executive.cpp
Author: Carlos Emil De Vera
KU ID: 2925639
Assignment: EECS268 Lab #1
Date: 9/5/2020
*/
#include "Executive.h"
#include "Game.h"
#include <iostream>
#include <fstream>

Executive::Executive(std::string file)
{
    m_FileIn = file;
}


Executive::~Executive()
{
    delete[] m_newGames;
}


void Executive::run()
{
    createGames();
    do
    {
        printMenu();
        std::cin >> m_UserChoice;
        if (m_UserChoice <= 0 || m_UserChoice > 6)
        {
            std::cout << "Error: Invalid Choice. Try Again...\n";
        }
        else if(m_UserChoice==1)
        {
            for (int i =0; i< m_numGames;i++)
            {
                printGame(m_newGames[i]);
            }
        }
        else if(m_UserChoice==2)
        {
            findYear();
        }
        else if(m_UserChoice==3)
        {
            rankRange();
        }
        else if(m_UserChoice==4)
        {
            peopleVGibbons();
        }
        else if(m_UserChoice==5)
        {
            playTime();
        }
    } while (m_UserChoice != 6);

}

void Executive::printMenu()
{
    border();
    std::cout << "Choose one of the following options:\n";
    std::cout << "1. Print all games\n";
    std::cout << "2. Print all games from a year\n";
    std::cout << "3. Print a ranking range\n";
    std::cout << "4. The People VS Dr. Gibbons\n";
    std::cout << "5. Print based on play time\n";
    std::cout << "6. Exit the program\n";
    border();
}

void Executive::createGames()
{
    std::ifstream inFile;
    std::string tempName;
    double tempGibbRating, tempPubRating, tempMinTime;
    int tempYear, tempMinPlayers;
    
    inFile.open(m_FileIn);
    inFile >> m_numGames;
    m_newGames = new Game[m_numGames]; 

    for (int i = 0; i < m_numGames; i++)
    {
        inFile >> tempName >> tempGibbRating >> tempPubRating >> tempYear >> tempMinPlayers >> tempMinTime;
        m_newGames[i].setName(tempName);
        m_newGames[i].setGR(tempGibbRating);
        m_newGames[i].setPR(tempPubRating);
        m_newGames[i].setYear(tempYear);
        m_newGames[i].setMP(tempMinPlayers);
        m_newGames[i].setMT(tempMinTime);
    }

    inFile.close();
}

void Executive::printGame(Game object)
{
    std::cout << object.getName() << " (" << object.getYear() << ") [GR=";
    std::cout << object.getGR() << ", PR=" << object.getPR() << " , MP=";
    std::cout << object.getMP() << ", MT=" << object.getMT() << "]\n";
}

void Executive::findYear()
{
    int targetYear, tempYear;
    bool targetFound = false;
    std::cout << "Input in a valid year you would like to search in: ";
    std::cin >> targetYear; std::cout << "\n";
    while (targetYear <=0)
    {
        std::cout << "ERROR: You have input in an invalid Year, try again: ";
        std::cin >> targetYear; std::cout << "\n";
    }

   for (int i = 0; i < m_numGames; i++)
   {
       tempYear=m_newGames[i].getYear();
       if (tempYear==targetYear)
       {
           printGame(m_newGames[i]);
           targetFound = true;
       }
   }       
   if (targetFound==false)
    {
       std::cout <<"No games found\n";
    }
}

void Executive::rankRange()
{
    double lowRange, highRange, temp1;
    std::cout << "Input in a valid lower limit for the range(1-10) you would like to search in: ";
    std::cin >> lowRange; std::cout << "\n";
    while (lowRange <= 0)
    {
        std::cout << "ERROR: You have input in an invalid lower limit for the range(1-10), try again: ";
        std::cin >> lowRange; std::cout << "\n";
    }
    std::cout << "Input in a valid upper limit for the range(1-10) you would like to search in: ";
    std::cin >> highRange; std::cout << "\n";
    while (highRange > 10)
    {
        std::cout << "ERROR: You have input in an invalid upper limit for the range(1-10), try again: ";
        std::cin >> highRange; std::cout << "\n";
    }

   for (int i = 0; i < m_numGames; i++)
   {
       temp1 = m_newGames[i].getGR();
       if (temp1 >=lowRange && temp1<=highRange)
       {
           printGame(m_newGames[i]);
       }
   }
}

void Executive::peopleVGibbons()
{
    double targetRange, temp1,temp2,temp3;
    std::cout << "Input in a valid range(0-10) you would like to search in: ";
    std::cin >> targetRange; std::cout << "\n";
    while (targetRange < 0 || targetRange > 10)
    {
        std::cout << "ERROR: You have input in an invalid range(0-10), try again: ";
        std::cin >> targetRange; std::cout << "\n";
    }

   for (int i = 0; i < m_numGames; i++)
   {
       temp1 = m_newGames[i].getPR();
       temp2 = m_newGames[i].getGR();
       temp3 = abs(temp2 - temp1);

       if (temp3 <=targetRange)
       {
           printGame(m_newGames[i]);
       }
   }
}

void Executive::playTime()
{
    double target, temp1;
        std::cout << "Input in a valid minimum playtime (minutes) you would like to search in: ";
    std::cin >> target; std::cout << "\n";
    while (target <=0)
    {
        std::cout << "ERROR: You have input in an invalid minimum playime (minutes), try again: ";
        std::cin >> target; std::cout << "\n";
    }

   for (int i = 0; i < m_numGames; i++)
   {
       temp1=m_newGames[i].getMT();
       if (temp1<=target)
       {
           printGame(m_newGames[i]);
       }
   }       
}

double Executive::abs(double input)
{
    if (input < 0)
    {
        return (-1*input);
    }
    else
    {
        return (input);
    }
}

void Executive::border()
{
    std::cout << "\n\n";
    for (int i =0; i <= 40; i++)
    {
        std::cout<<'*';
    }
    std::cout << "\n\n";
}


