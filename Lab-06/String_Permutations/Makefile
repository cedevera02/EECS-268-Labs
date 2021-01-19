#File name: Makefile
#Author: Carlos De Vera
#KU ID: 2925639
#Assignment: EECS268 Lab #6
#Date: 10/14/2020

perm: main.o Permutations.o
	g++ -std=c++11 -g -Wall main.o Permutations.o -o perm

main.o: main.cpp Node.h Node.cpp Stack.h Stack.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Permutations.o: Permutations.h Permutations.cpp
	g++ -std=c++11 -g -Wall -c Permutations.cpp

clean:
	rm *.o perm
