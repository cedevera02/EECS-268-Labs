#File name: Makefile
#Author: Carlos De Vera
#KU ID: 2925639
#Assignment: EECS268 Lab #6
#Date: 10/14/2020

fib: main.o Fibonacci.o
	g++ -std=c++11 -g -Wall main.o Fibonacci.o -o fib

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Fibonacci.o: Fibonacci.h Fibonacci.cpp
	g++ -std=c++11 -g -Wall -c Fibonacci.cpp

clean:
	rm *.o fib