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
#define MY_VAR(i, ptr) fprintf(stdout, "\n%s, which is valued at: %d which is at %p location\n", #i, *ptr, (void*)ptr);
// # in a macro converts it into a string
// Casting the ptr to a void* because %p specifier expects a generic pointer 
// Modern compilers are smart enough to correct this like gcc or Clang

// int is 4 bytes
// char is 1 byte

#include<stdio.h>

int main(){
    int i = 72;
    int* ptr = &i;

    MY_VAR(i, ptr);

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
