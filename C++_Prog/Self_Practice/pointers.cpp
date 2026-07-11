// Pointers are like a street with a row of houses. 
// It is a direction sign to the memory address of the memory location in the RAM. 

// It is a Integer that holds a memory address. 

// Types are just an abstraction of the data that is stored in the memory for programmers to understand.

#include <iostream>
#include <bits/stdc++.h> // For memset 

// Macro for easy printing to the screen.
#define LOG(x) std::cout << x << std::endl;

int main(){
    // Created on the stack
    int var = 7;

    // Created on the heap
    char* buffer = new char[8]; // 8 bytes of memory allocated on the heap.
    memset(buffer, 0, 8); // memset is used to set the memory to a specific value. Here it is set to 0.
    delete[] buffer; // Free the memory allocated on the heap.

    // Double pointer 
    char** ptr = &buffer; // ptr is a pointer to a pointer. It points to the address of buffer.
    // This is useful for passing a pointer to a function and modifying the pointer itself.
    
    // Create a void pointer. (It is typeless pointer)
    // Used for passing unspecified data types to functions. malloc and calloc use this.
    //void* ptr = 0;
    // Could also write void* ptr = NULL;
    // NULL is hashdefine for 0.
    // Could write: nullptr (C++11) instead of NULL or 0.

    // Pointer size depends on the architecture of the system. 
    // Usually 64 bit or 32 bit
    
    // 8
    int* ptr2 = &var; // ptr2 is a void pointer that points to the address of var.

    // Dereferencing a void pointer is not allowed! So no void ptr2 = &var and then *ptr2 = 21; is allowed.
    // Computer doesnt know  what type it is.

    *ptr2 = 21;
    std::cin.get(); // to prevent the console from closing immediately after running the program. 
    // User has to enter any key into buffer to close the console.
}

// Compile with debug symbols:
// g++ -g pointers.cpp -o pointers.exe

// Run: 
// gdb .\pointers.exe

// layout split
// break 20
// break 43

// run
// print var
// print buffer // Gives the address of the buffer.
// print *buffer // Gives the value of the first byte of the buffer. (0 in this case)

// To get info on breakpoints:
// info breakpoints
// To delete a breakpoint:
// delete 1 2 3 // Number of the breakpoint(s) to del.
// Can range using 1-4 ...





