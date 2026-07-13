# Simple makefile 

# Config 
CC = gcc
CFLAGS = -Wall -Wextra -std=c23

all: one.c two.c
	$(CC) $(CFLAGS) one.c -o one.exe
	$(CC) $(CFLAGS) two.c -o two.exe

run: all
	./one.exe
	./two.exe