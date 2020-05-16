#Makefile for Assignment 4
#Alexander Zimmermann ZMMALE001

CC=g++

CCFLAGS = -std=c++17
LDFLAGS = -I./eigen-3.3.7

SRC = $(wildcard src/*.cpp *.h)
OBJ = $(SRC:.cpp=.o)

PROG = PCA

$(PROG) : $(OBJ)
	$(CC) $(CCFLAGS) $(SRC)$(LDFLAGS) -o PCA


depend:
	$(CC) -M $(SRC) > incl.defs

clean:
	rm -f *.o
	rm -f PCA
