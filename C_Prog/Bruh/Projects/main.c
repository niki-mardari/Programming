#include <stdio.h>
#include <unistd.h> //For read() and STDIN_FILENO
#include <termios.h> // For tctgetattr()

// To Do: Add comments explaining each line

// To turn off echoing
void enableRawMode(){
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main(){
    enableRawMode();

    char c;
    while(read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}