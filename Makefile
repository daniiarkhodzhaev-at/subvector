.PHONY: all clean clean-main clean-libs test

CPPFLAGS=-O2 -Wall -Wextra -g

all: main

clean: clean-main clean-libs clean-tests

test: tests/test_subvector
	valgrind ./tests/test_subvector

clean-main:
	rm -vf main
	rm -vf main.o

clean-libs:
	rm -vf libsubvector.so
	rm -vf subvector.o

clean-tests:
	rm -vf tests/test_subvector.o
	rm -vf tests/test_subvector

main: main.o libsubvector.so
	$(CXX) -o main main.o -L. -lsubvector

main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c -o main.o main.cpp -I.

subvector.o: subvector.cpp subvector.hpp

libsubvector.so: subvector.o
	$(CXX) -shared -fPIC -fpic -o libsubvector.so subvector.o

tests/test_subvector: tests/test_subvector.o libsubvector.so
	$(CXX) -o tests/test_subvector tests/test_subvector.o -L. -lsubvector

tests/test_subvector.o: tests/test_subvector.cpp subvector.hpp
	$(CXX) -c -o tests/test_subvector.o tests/test_subvector.cpp -I.
