.PHONY: all clean

CPPFLAGS=-O2 -Wall -Wextra

all: main

main: main.o libsubvector.so
	g++ -o main main.o -L. -lsubvector

main.o: main.cpp
	g++ -c -o main.o main.cpp -I. $(CPPFLAGS)

subvector.o: subvector.cpp subvector.hpp
	g++ -c -o subvector.o subvector.cpp

libsubvector.so: subvector.o
	gcc -shared -fPIC -fpic -o libsubvector.so subvector.o
