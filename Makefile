#Makefile for Assignment 4
#Alexander Zimmermann ZMMALE001

CC=g++

CCFLAGS = -std=c++17 -I./eigen-3.3.7


SRC = $(wildcard src/main.cpp)
OBJ = $(SRC:.cpp=.o)

PROG = PCA

$(PROG) : $(OBJ)
	$(CC) $(CCFLAGS) $(SRC) -o PCA


depend:
	$(CC) -M $(SRC) > incl.defs

clean:
	rm -f *.o
	rm -f PCA
