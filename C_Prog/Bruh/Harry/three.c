// Recursion, a funciton that calls itself

#include<stdio.h>
#include<stdint.h>
#include<math.h>

// Factorial
// O(2^N) exponential time 
int factorial(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    return n * factorial(n - 1);
}

// Simpler 
void fact(int n){
    int ans = n;
    int copy = n;
    for(int i = copy - 1; i > 0; --i){
        ans *= i;
        copy--;
    }
    fprintf(stdout, "\n%d Factorial is: %d\n", n, ans);
}

int main(){

    fprintf(stdout, "\nThe value of %d recursive factorial is: %d\n", 5, factorial(5));
    fact(5);
    return 0;
}