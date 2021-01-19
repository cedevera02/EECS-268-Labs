#File name: Makefile
#Author: Carlos De Vera
#KU ID: 2925639
#Assignment: EECS268 Lab #1
#Date: 9/5/2020


lab1: main.o Executive.o Game.o
	g++ -std=c++11 -g -Wall main.o Executive.o Game.o -o lab1

main.o: main.cpp Executive.h Game.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Game.o: Game.h Game.cpp
	g++ -std=c++11 -g -Wall -c Game.cpp

clean:
	rm *.o lab1