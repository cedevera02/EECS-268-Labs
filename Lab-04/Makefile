#File name: Makefile
#Author: Carlos De Vera
#KU ID: 2925639
#Assignment: EECS268 Lab #4
#Date: 9/23/2020


lab4: main.o Executive.o Elevator.o myException.o
	g++ -std=c++11 -g -Wall main.o Executive.o Elevator.o myException.o -o lab4

main.o: main.cpp Node.h Node.cpp Stack.h StackInterface.h Stack.cpp QueueInterface.h Queue.h Queue.cpp Executive.h Elevator.h myException.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Elevator.o: Elevator.h Elevator.cpp
	g++ -std=c++11 -g -Wall -c Elevator.cpp

myException.o: myException.h myException.cpp
	g++ -std=c++11 -g -Wall -c myException.cpp

clean:
	rm *.o lab4