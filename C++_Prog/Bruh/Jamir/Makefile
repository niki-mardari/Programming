# Me makefile

# Flags
CC = g++
CC2 = clang++
CFLAGS = -Wall -Wextra -std=c++23

.PHONY: all run clean one two

all: one.cpp two.cpp
	$(CC) $(CFLAGS) one.cpp -o one.exe
	$(CC2) $(CFLAGS) two.cpp -o two.exe

run: all
	./one.exe
	./two.exe

one:
	./one.exe

two:
	./two.exe

clean:
	rm -rf *.exe
