// Pass by reference and 
// pass by value
// into functions

#include<stdio.h>

int sum(int, int); // Prototype of call by value
int subtract(int*, int*); // Protoype call by reference 
void swap(int *x, int *y); // Prototype for call by reference and swapping variables

int main(){

    int x = 5, y = 4;
    printf("\nThe value of x + y = %d", sum(x, y));
    printf("\nThe value of x and y are: %d and %d\n", x, y);

    printf("\nThe value of x is passed by reference and changed to 56");
    printf("\nThe value of x - y = %d", subtract(&x, &y));
    printf("\nThe value of x and y are: %d and %d\n", x, y);

    swap(&x, &y);

    return 0;
}

// Pass by value, passing a variable by copy 
int sum(int x, int y){
    // a = 67;
    return x + y;
}

// Pass by reference
int subtract(int *x, int *y){
    *x = 56;
    return *x - *y;
}

void swap(int *x, int *y){
    int temp = 0;
    printf("\nValues before swap: x = %d, y = %d, temp = %d\n", *x, *y, temp);
    temp = *x;
    *x = *y;
    *y = temp;
    printf("\nValues after swap: x = %d, y = %d, temp = %d\n", *x, *y, temp);
}