# Makefile for Project1
# Written by Stewart Weiss 
# This is designed for the first project in CSci 335, Spring 2018
# It assumes that the source files in the project are exactly those specified
# in the assignment: 
# main.cpp, pseudoserver.cpp, pseudoserver.h, tree.cpp, tree.h, bitcoin.h
# and that the dependencies are that main includes all header files and
# otherwise the remaining cpp files are independent (do not include any 
# header files other than there own.)
#
# Instructions:
# If you create other files, you need to modify this makefile.
#
# Type  make to build the executable, which is named Project1
# Type make clean to remove all .o files
# Type make cleanall to remove all .o files and the Project1 executable.

# If you want to force a recompile, type "touch *.cpp" and then "make"

CXX       := /usr/bin/g++
CXXFLAGS  += -W -g 

all: Project1

.PHONY: clean  cleanall
clean:
	rm -f *.o

cleanall:
	rm -f *.o Project1
	
Project1:  pseudoserver.o tree.o main.o bitcoin.o inputHandler.o
	$(CXX) $(CXXFLAGS) -o Project1  main.o pseudoserver.o tree.o bitcoin.o inputHandler.o

main.o: main.cpp pseudoserver.h tree.h bitcoin.h 
	$(CXX) $(CXX_FLAGS)  -c main.cpp

pseudoserver.o: pseudoserver.cpp pseudoserver.h 
	$(CXX) $(CXX_FLAGS)  -c pseudoserver.cpp

tree.o: tree.cpp tree.h
	$(CXX) $(CXX_FLAGS) -c tree.cpp

bitcoin.o: bitcoin.h
	$(CXX) $(CXX_FLAGS) -c bitcoin.cpp

inputHandler.o: inputHandler.cpp inputHandler.h
	$(CXX) $(CXX_FLAGS) -c inputHandler.cpp
