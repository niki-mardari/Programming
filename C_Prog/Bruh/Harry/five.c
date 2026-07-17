// Pass by reference and 
// pass by value
// into functions

#include<stdio.h>

int sum(int, int); // Prototype

int main(){
    printf("\nThe value of a + b = %d", sum(5, 4));
    return 0;
}

// Pass by value, passing a variable by copy 
int sum(int a, int b){

    return a + b;
}
