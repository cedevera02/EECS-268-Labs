/*
File name: BrowserHistory.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #5
Date: 10/3/2020
*/

#include "BrowserHistory.h"


BrowserHistory::BrowserHistory()
{
    m_history = new LinkedList<std::string>;
    m_current = 0;
}

BrowserHistory::~BrowserHistory()
{
    m_history->clear();
    delete m_history;
}

void BrowserHistory::navigateTo(std::string url)
{
    int leng = m_history->length();
    if (leng == m_current)
    {
        try
        {
            m_history->insert (m_current + 1, url);
            m_current++;
        }
        catch (std::runtime_error& rte)
        {
            std::cout << rte.what();
        }
    }
    else
    {
        int leng = m_history->length();
       for (int i = m_current+1; i <= leng; i++)
       {
            try
            {
                m_history->remove(m_current+1);
            }
            catch (std::runtime_error& rte)
            {
                std::cout << rte.what();
            }
       }
        try
        {
            m_history->insert (m_current + 1, url);
            m_current++;
        }
        catch (std::runtime_error& rte)
        {
            std::cout << rte.what();
        }
    }
}

  /**
  * @pre none
  * @post if possible, the browser navigates forward in the history otherwise it keeps focus
  *         on the current URL
  */
  void BrowserHistory::forward()
  {
      if (m_current != (m_history->length()))
      {
          m_current++;
      }
  }

  /**
  * @pre none
  * @post if possible, the browser navigates backwards in the history otherwise it keeps focus
  *         on the current URL 
  */
  void BrowserHistory::back()
  {
      if (m_current != 1)
      {
          m_current--;
      }
  }

  std::string BrowserHistory::current() const
  {
      try 
      {
          return (m_history->getEntry(m_current));
      }
      catch (std::runtime_error& rte)
      {
          return (rte.what());
      }
  }

  void BrowserHistory::copyCurrentHistory(ListInterface<std::string>& destination)
  {
      m_history->clear();
      for (int i = 1; i <= destination.length(); i++)
      {
          m_history->insert(i,destination.getEntry(i));
          m_current = i;
      }
      
  }

void BrowserHistory::printHistory()
{
    std::cout << "\n\nOldest\n\n";
    for (int i =0; i <12; i++)
    {
        std::cout << "=";
    }
    std::cout << "\n";

    for (int i = 1; i <= m_history->length(); i++)
    {
        if (i == m_current)
        {
            std::cout << m_history->getEntry(i);
            std::cout << "\t<==current\n";
        }
        else
        {
            std::cout << m_history->getEntry(i) << '\n';
        }
    }

    for (int i =0; i <12; i++)
    {
        std::cout << "=";
    }

    std::cout << "\n\nNewest\n\n";

}