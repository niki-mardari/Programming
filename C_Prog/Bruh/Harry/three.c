// Recursion, a funciton that calls itself

#include<stdio.h>
#include<stdint.h>

// Factorial Recursive version
// Time complexity O(N) Linear time
int factorial(int n){
    if(n <= 1){
        return 1;
    }
    return n * factorial(n - 1);
}

// Factorial
// O(2^N) exponential time 
void fact(int n){
    int ans = 1;
    // Skipped 1 
    for(int i = 2; i <= n; i++){
        ans *= i;
    }
    fprintf(stdout, "\nThe value of %d iterative Factorial is: %d\n", n, ans);
}

// Celsius to Fahrenheit 
void ctok(double c){
    double conversion = (c * (9.0/5.0)) + 32;
    fprintf(stdout, "\n%.2lf" "\xF8" "C in Fahrenheit is %.2lf\n", c, conversion);
    // Had to use "\xF8" from Code page 437
}

// Force of attraction 
void attraction(int m){
    double force = m * (9.8);
    fprintf(stdout, "\nThe force of attraction of a body with mass 55Kg is: %.2lf\n", force);
}

// Basic Fib
void fib(int n){
    if(n == 0) {
        printf("\n0\n");
    }
    else{
    int first = 0, second = 1;
    fprintf(stdout, "\n%d,%d,", first, second);
    for(int i = 0; i < n - 2; i++){
        if(i == 0) {
        fprintf(stdout, "%d,", first + second);
        continue;
    }
        int next = first + second;
        first = second;
        second = next;
        fprintf(stdout, "%d,", first + second);
        }
    }
}

// Better Fibonacci
int fibonacci(int n){
    if(n == 1 || n == 2) return 1; 
    else if(n <= 0) return 0;
    return fibonacci(n-1) + fibonacci(n-2);
}

// Sum of N natural numbers 
int sum(int n){
    // Need a base condition or else infinite!
    if(n == 1) return 1;
    return sum(n - 1) + n;
}

void ladder(int n){
    int stars = 1;
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= stars; j++){
        printf("* ");
        }
        stars += 2;
        printf("\n");
    }
} 

int main(){

    fprintf(stdout, "\nThe value of %d recursive factorial is: %d Kgm/s^2 or Newtons\n", 5, factorial(5));
    fact(5);
    ctok(28);
    attraction(55.1);
    fib(0);
    fprintf(stdout, "\n%d,\n", fibonacci(0));
    fprintf(stdout, "\nSum of %d is %d.\n", 5, sum(5));


    // Don't do this!
    // int a = 5;
    // printf("\n%d %d %d\n", a, ++a, a++); // Compiler evals right to left, could be in reverse depending on how compiler works
    // Compiler gets a = 5 adds 1,
    // a is now 6 and adds ++a 
    // a is now 7
    // Output: 7 7 5

    ladder(5);

    return 0;
}
