# Me makefile

# Flags
CC = g++
CC2 = clang++
CFLAGS = -Wall -Wextra -std=c++23

.PHONY: all run clean one two

all: one.cpp two.cpp
	$(CC) $(CFLAGS) one.cpp -o one.exe
	$(CC) $(CFLAGS) two.cpp -o two.exe -lgdi32

run: all
	./one.exe
	./two.exe
	./three.exe

one:
	./one.exe

two:
	./two.exe

clean:
	rm -rf *.exe
