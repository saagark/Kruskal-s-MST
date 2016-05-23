
CXX=g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter

all: prog2

prog2: main.o kruskal.o
	${CXX} $^ -o $@

clean: 
	/bin/rm -f prog2 *.o