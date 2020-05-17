#Makefile for Assignment 5
#Alexander Zimmermann ZMMALE001

eigenCalcultor: main.o
	g++ main.o -o egienCalculator

main.o:
	g++ -c main.cpp -std=c++11

