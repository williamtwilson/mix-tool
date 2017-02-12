CC=clang++
CFLAGS=-std="c++14"
SOURCES=Source/*.cpp main.cpp

all:
	$(CC) $(SOURCES) $(CFLAGS) -o mix
