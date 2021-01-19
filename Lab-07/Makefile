#File name: Makefile
#Author: Carlos De Vera
#KU ID: 2925639
#Assignment: EECS268 Lab #7
#Date: 10/21/2020

lab7: main.o ReadMaze.o MazeWalker.o
	g++ -std=c++11 -g -Wall main.o ReadMaze.o MazeWalker.o -o lab7

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

ReadMaze.o: ReadMaze.h ReadMaze.cpp
	g++ -std=c++11 -g -Wall -c ReadMaze.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -std=c++11 -g -Wall -c MazeWalker.cpp

clean:
	rm *.o lab7