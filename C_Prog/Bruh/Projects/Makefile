# Haha yes 

.PHONY: all clean main guess uefa

# variables 
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c23
# Wall for all extra warnings
# Wextra for extra warnings or can use -pedantic 
# -std=c23 for C23 standard

all: main.c guess.c
#	$(CC) $(CFLAGS) main.c -o main.exe
	$(CC) $(CFLAGS) guess.c -o guess.exe
	$(CC) $(CFLAGS) uefa.c -o uefa.exe

guess: guess.c
	./guess.exe

uefa: uefa.c
	./uefa.exe

clean: 
	rm -f *.exe