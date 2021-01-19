/*
File name: Game.cpp
Author: Carlos Emil De Vera
KU ID: 2925639
Assignment: EECS268 Lab #1
Date: 9/5/2020
*/

#include "Game.h"
#include <iostream>

    Game::Game()
    {
        m_Name="";
        m_GR=0.0;
        m_PR=0.0;
        m_MT=0.0;
        m_Year=0;
        m_MP=0;
    }
    

    void Game::setName(std::string name)
    {
        m_Name=name;
    }

    void Game::setGR(double gRate)
    {
        m_GR=gRate;
    }

    void Game::setPR(double pRate)
    {
        m_PR=pRate;
    }

    void Game::setMT(double time)
    {
        m_MT=time;
    }

    void Game::setYear (int year)
    {
        m_Year=year;
    }

    void Game::setMP (int people)
    {
        m_MP=people;
    }

    std::string Game::getName()
    {
        return (m_Name);
    }

    double Game::getGR()
    {
        return(m_GR);
    }

    double Game::getPR()
    {
        return(m_PR);
    }

    double Game::getMT()
    {
        return(m_MT);
    }

    int Game::getYear ()
    {
        return(m_Year);
    }

    int Game::getMP ()
    {
        return(m_MP);
    }