# Simple makefile 

# Config 
CC = gcc
CFLAGS = -Wall -Wextra -std=c23

# To prevent make from thinking that the targets are files, we can use .PHONY to declare them as phony targets. This is useful for targets that do not represent actual files, such as "clean" or "run".
.PHONY : all run clean one two three four

all: one.c two.c three.c
	$(CC) $(CFLAGS) one.c -o one.exe
	$(CC) $(CFLAGS) two.c -o two.exe
	$(CC) $(CFLAGS) three.c -o three.exe
	$(CC) $(CFLAGS) four.c -o four.exe

run: all
	./one.exe
	./two.exe
	./three.exe

one:
	./one.exe

two:
	./two.exe

three:
	./three.exe

four:
	./four.exe

clean:
	rm -f *.exe