// Revising pointers in c
// A program is loaded into Ram.
// Ram has blocks 

// Example blocks: 
// 8 Bits in each row

// 8 bits is 1 byte
// 1000 bytes is 1kb
// 1000kb is 1mb
// 1024 mb is 1 Gb

// Need a macro in define to convert argument into string
#define MY_VAR(i, ptr) fprintf(stdout, "\nThe variable %s, which is valued at: %d which is at %p location\n", #i, *ptr, (void*)ptr);
// # in a macro converts it into a string
// Casting the ptr to a void* because %p specifier expects a generic pointer 
// Modern compilers are smart enough to correct this like gcc or Clang
// #define CONCAT(a, b) a ## b // Combine tokens
// #define TO_STRING(x) #x // Stringify a token
// #define CONCAT_TO_STRING(a, b) TO_STRING(CONCAT(a, b)) // Merges, then stringifies
// ## concatenates or merges two tokens into a new single string

// int is 4 bytes
// char is 1 byte

#include<stdio.h>

int main(){
    int x = 72;
    int j = 67;
    int* ptr = &x;

    MY_VAR(x, ptr);
    MY_VAR(j, &j);

    // Can also do it this way:
    printf("\nThe memory address of x is %p", &x);
    printf("\nThe memory address of j is %p", &j);

    // i and j are 4 bytes adjacent in ram/ stack. int gets allocated 4 bytes
    fprintf(stdout,"\nThe stack pointer difference is: %lld bytes (1) * (4) bytes", &x - &j); // c automatically assumes pointer is in int (4 bytes)
    fprintf(stdout,"\nOr %lld bytes\n", (char* )&x - (char* )&j); // Convert to char (1 bytes)

    return 0; 
}

// To get assembly code run: 
// gcc -S -fverbose-asm -g four.c -o assembly.txt
// -S tells to stop after compilation and output the assembly instead of binary 
// -fverbose-asm tells to add comments 
// -g tells to add debugging info like c code comments with asm 

// Record asm in GDB:
// gdb ./four.exe
// break main
// run
// set logging file assembly.txt
// set logging redirect on
// set logging enabled on
// disassemble /m main 
// /m for linking each c line with asm instructions
// Stop recording:
// set logging enabled off 
// quit

// In GDB:
// gdb ./four.exe
// break main
// run
// print &i
// print ptr
// layout split
// layout regs --> To view the registers 
