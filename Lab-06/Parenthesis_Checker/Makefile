#File name: Makefile
#Author: Carlos De Vera
#KU ID: 2925639
#Assignment: EECS268 Lab #6
#Date: 10/14/2020

parens: main.o Parenthesis.o
	g++ -std=c++11 -g -Wall main.o Parenthesis.o -o parens

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Parenthesis.o: Parenthesis.h Parenthesis.cpp
	g++ -std=c++11 -g -Wall -c Parenthesis.cpp

clean:
	rm *.o parens