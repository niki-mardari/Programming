#include<stdio.h>
#include<stdint.h> 
#include<stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

void doShit(){
    int n = 5;
    // scanf("%d", &n);
    int z = 0; // Sub
    // int k = 2;
    // int x = ((n-1)+n)-k; // Amount of 1s -> ((n-1)+n)-k -> k++2
    // int y = n - x; // Amount of 0s -> n - x
    int val = n;
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