#File name: Makefile
#Author: Carlos De Vera
#KU ID: 2925639
#Assignment: EECS268 Lab #2
#Date: 9/9/2020


lab2: main.o Executive.o ShapeContainer.o Circle.o Rectangle.o Triangle.o
	g++ -std=c++11 -g -Wall main.o Executive.o ShapeContainer.o Circle.o Rectangle.o Triangle.o -o lab2

main.o: main.cpp Executive.h Shape.h ShapeContainer.h Circle.h Rectangle.h Triangle.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

ShapeContainer.o: ShapeContainer.h ShapeContainer.cpp
	g++ -std=c++11 -g -Wall -c ShapeContainer.cpp

Circle.o: Circle.h Circle.cpp
	g++ -std=c++11 -g -Wall -c Circle.cpp
	
Rectangle.o: Rectangle.h Rectangle.cpp
	g++ -std=c++11 -g -Wall -c Rectangle.cpp

Triangle.o: Triangle.h Triangle.cpp
	g++ -std=c++11 -g -Wall -c Triangle.cpp

clean:
	rm *.o lab2