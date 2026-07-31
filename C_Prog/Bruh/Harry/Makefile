# Simple makefile 

# Config 
CC = gcc
CFLAGS = -Wall -Wextra -std=c23

# To prevent make from thinking that the targets are files, we can use .PHONY to declare them as phony targets. This is useful for targets that do not represent actual files, such as "clean" or "run".
.PHONY : all run clean one two three four five six seven eight nine ten eleven

all: one.c two.c three.c four.c five.c six.c seven.c eight.c nine.c ten.c eleven.c
	$(CC) $(CFLAGS) one.c -o one.exe
	$(CC) $(CFLAGS) two.c -o two.exe
	$(CC) $(CFLAGS) three.c -o three.exe
	$(CC) $(CFLAGS) four.c -o four.exe
	$(CC) $(CFLAGS) five.c -o five.exe
	$(CC) $(CFLAGS) -g  six.c -o six.exe
	$(CC) $(CFLAGS) -g  seven.c -o seven.exe
	$(CC) $(CFLAGS) -g  eight.c -o eight.exe
	$(CC) $(CFLAGS) -g  nine.c -o nine.exe
	$(CC) $(CFLAGS) -g  ten.c -o ten.exe
	$(CC) $(CFLAGS) -g eleven.c -o eleven.exe
	
run: all
	./one.exe
	./two.exe
	./three.exe
	./four.exe
	./five.exe
	./six.exe
	./seven.exe
	./eight.exe
	./nine.exe
	./ten.exe
	./eleven.exe

one:
	./one.exe

two:
	./two.exe

three:
	./three.exe

four:
	./four.exe

five:
	./five.exe

six:
	./six.exe

seven:
	./seven.exe

eight:
	./eight.exe

nine:
	./nine.exe

ten:
	./ten.exe

eleven:
	./eleven.exe

clean:
	rm -f *.exe
