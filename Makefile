CC=clang++
CFLAGS=-std="c++14"
DFLAGS=-Wall -g
SOURCES=Source/*.cpp main.cpp

all:
	$(CC) $(SOURCES) $(CFLAGS) -o mix

debug:
	$(CC) $(SOURCES) $(CFLAGS) $(DFLAGS) -o mix_debug

