#File name: Makefile
#Author: Carlos De Vera
#KU ID: 2925639
#Assignment: EECS268 Lab #9
#Date: 11/11/2020

lab9: main.o Pokemon.o Executive.o
	g++ -std=c++11 -g -Wall main.o Pokemon.o Executive.o -o lab9

main.o: main.cpp BinaryNode.h BinaryNode.cpp BinarySearchTree.h BinarySearchTree.cpp BinarySearchTreeInterface.h
	g++ -std=c++11 -g -Wall -c main.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o lab9