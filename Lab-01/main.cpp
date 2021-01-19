/*
File name: main.cpp
Author: Carlos Emil De Vera
KU ID: 2925639
Assignment: EECS268 Lab #1
Date: 9/5/2020
*/

#include <iostream>
#include "Executive.h"
int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Executive exec(argv[1]); //sample creation of executive object
     exec.run(); //presumably handles the calling of all other member methods
  }

  return(0);
}