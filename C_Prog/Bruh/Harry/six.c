// Practice exercises done
// Failed to manipulate a pointer to a pointer k to change the 

#include<stdio.h>

#define MY_VAR(i, ptr) printf("\nThe variable %s is stored in memory location %p and the value is %d\n", #i, ptr, *ptr);

void add(int i, int j){
    printf("\n i + j = %d\n", i + j);
    printf(" \nIn a pass by value func, the location of i is: %p location of j is: %p\n", &i, &j);    
}

void multiply(int* j){
    printf("\nThe variable j is at at address %p and the value stored there is: %d\n", j, *j);
    *j *= 10;
    printf("\nThe new value of j is at at address %p and the value stored there is now : %d\n", j, *j);
    *j /= 10;
}

void sumavg(int* i, int* j){
    int sum = *i + *j;
    float avg = sum / 2.0f;
    printf("\n i + j = %d, avg = %.2f\n", sum, avg);
}

void printPointerVal(int** k){
    printf("\nThe value at pointer address %p is %d\n", *k, **k);
}

void changePtr(int* ptr){
    ptr -= 1; // Depends on system addressing!
    printf("\nThe value that ptr points to now is: %d\n", *ptr);
}

int main(){
    int i = 7, j = 2;
    int* ptr = &i;
    int **k;
    k = &ptr;

    MY_VAR(i, ptr);
    printf("\nIn a pass by reference func, the variable j is at at address %p and the value stored there is: %d\n", &j, j);

    multiply(&j);

    add(i, j);

    sumavg(&i, &j);

    printPointerVal(k);
    printf("%d", *ptr);

    changePtr(ptr);
    
    return 0; 
}

