# Me makefile

# Flags
CC = g++
CC2 = clang++
CFLAGS = -Wall -Wextra -std=c++23

.PHONY: all run clean one

all: one.cpp
	$(CC2) $(CFLAGS) one.cpp -o one.exe

run: all
	./one.exe

one:
	./one.exe

clean:
	rm -rf *.exe
