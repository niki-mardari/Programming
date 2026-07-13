#include<stdio.h>
#include<stdint.h> 
#include<stdlib.h>
#include<math.h>

#ifdef _WIN32
#include <windows.h>
#endif

void area_rect(int a, int b){
    int area = a * b;
    printf("\nArea Rectangle = %d", area);
}

void interest(float P, float r, int n, int t){
    int power = n * t;
    double total = P;

    for(int i = 0; i < power; i++){
        total *= (1 + (r / n));
    }
    printf("\nThe final ampunt with interest is: %.2f\n", total);
}

void doShit(){
    int n = 5;
    int z = 0; // Sub
    int val = n;
    //int c = (n==z)?6:7;
    int count = 0;

  	// print my pattern.
    for(int i = 0; i < ((n - 1) + n); i++){
        for(int j = 0; j < ((n - 1) + n); j++){
                if(count == 0){
                    
                }
                printf("%d", abs(val));        
        }
        printf("\n");
        val = val - z;
        z++;
    }
}

int main(){

    // Force the Windows Terminal to use UTF-8 encoding
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    char* buffer = malloc(9);

    for(uint32_t i = 0; i++ < 9;){
        buffer[i] = (char)(65 + i);
    }
    buffer[8] = '\0'; // Need this one

    for(uint32_t i = 0; i < 5; i++){
        fprintf(stdout, "%s\n", buffer);
    }
    printf("Я люблю\nпрограмировать\nХаха!!!!!\n");

    free(buffer);

    doShit();

    return 0;
}