#File name: Makefile
#Author: Carlos De Vera
#KU ID: 2925639
#Assignment: EECS268 Lab #8
#Date: 11/4/2020

lab8: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o lab8

main.o: main.cpp Sorts.h Sorts.cpp SortTimer.h SortTimer.cpp ArrayCreator.h ArrayCreator.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o lab8