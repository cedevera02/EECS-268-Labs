#File name: Makefile
#Author: Carlos De Vera
#KU ID: 2925639
#Assignment: EECS268 Lab #5
#Date: 10/3/2020

lab5: main.o BrowserHistory.o Executive.o
	g++ -std=c++11 -g -Wall main.o BrowserHistory.o Executive.o -o lab5

main.o: main.cpp Executive.h ListInterface.h Node.h Node.cpp LinkedList.h LinkedList.cpp BrowserHistoryInterface.h BrowserHistory.h
	g++ -std=c++11 -g -Wall -c main.cpp

BrowserHistory.o: BrowserHistory.h BrowserHistory.cpp
	g++ -std=c++11 -g -Wall -c BrowserHistory.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o lab5
