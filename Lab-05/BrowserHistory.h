/*
File name: BrowserHistory.h
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #5
Date: 10/3/2020
*/

#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H

#include "BrowserHistoryInterface.h"
#include "LinkedList.h"
#include "Node.h"

class BrowserHistory: public BrowserHistoryInterface
{

  private:

    LinkedList<std::string>* m_history;
    int m_current;

  public:

  BrowserHistory();

  ~BrowserHistory();

  /**
  * @pre none
  * @post the browser navigate to the given url
  * @param url, a string representing a URL
  */
  void navigateTo(std::string url);

  /**
  * @pre none
  * @post if possible, the browser navigates forward in the history otherwise it keeps focus
  *         on the current URL
  */
  void forward();

  /**
  * @pre none
  * @post if possible, the browser navigates backwards in the history otherwise it keeps focus
  *         on the current URL 
  */
  void back();

  /**
  * @return the current URL 
  */
  std::string current() const;

  /**
  * @pre None
  * @post The list is cleared out, then the current browser history is copied into the given list  
  * @param destination, an empty list of strings
  */
  void copyCurrentHistory(ListInterface<std::string>& destination);

  /**
   * @pre None
   * @post Prints out the history of m_history fom oldest to newest
   * */
  void printHistory();
};

#endif