# Haha yes 

.PHONY: all clean guess

# variables 
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c23
# Wall for all extra warnings
# Wextra for extra warnings or can use -pedantic 
# -std=c23 for C23 standard

all: main.c guess.c
#	$(CC) $(CFLAGS) main.c -o main.exe
	$(CC) $(CFLAGS) guess.c -o guess.exe

guess: guess.c
	./guess.exe

clean: 
	rm -f *.exe