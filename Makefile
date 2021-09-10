.PHONY: all clean-all clean-main clean-libs

CPPFLAGS=-O2 -Wall -Wextra

all: main

clean: clean-main clean-libs

clean-main:
	rm -vf main
	rm -vf main.o

clean-libs:
	rm -vf libsubvector.so
	rm -vf subvector.o

main: main.o libsubvector.so
	$(CXX) -o main main.o -L. -lsubvector

main.o: main.cpp
	$(CXX) -c -o main.o main.cpp -I.

subvector.o: subvector.cpp subvector.hpp
	$(CXX) -c -o subvector.o subvector.cpp

libsubvector.so: subvector.o
	$(CXX) -shared -fPIC -fpic -o libsubvector.so subvector.o
