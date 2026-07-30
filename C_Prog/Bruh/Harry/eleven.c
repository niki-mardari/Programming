// Dynamic memory allocation

// C programming has fixed rules
// Memory allocation happens before runtime on the stack
// Need dynamic memory to allocate space during runtime for variables that we don't know the size of
// Can request memory in the heap
// Changin the size of an array is not allowed!

// malloc - memory allocation, returns void pointer
// calloc - contiguous memory allocation, initializes each memory block with a default 0
// free - Free the memory in the heap
// realloc - re allocation/ changing size of the memory in the heap using a pointer

// Source: https://www.geeksforgeeks.org/c/memory-layout-of-c-program/
/*
 * ============================================
 * Quick summary:
 *   Stack  -> local vars, shrinks/grows automatically
 *   Heap   -> dynamic memory, YOU manage it (malloc/free)
 *   BSS    -> uninitialized globals/statics (auto zeroed)
 *   Data   -> initialized globals/statics
 *   Text   -> the actual program instructions
 * ============================================
 */

#include <stdio.h>
#include <malloc.h>

// Basic malloc
void meAlloc()
{
    int *ptr;
    ptr = (int *)malloc(30 * sizeof(int)); // allocate 30 * 4 bytes = 120 bytes for 30 integers
    // malloc returns address in heap
    if (ptr == NULL)
    {
        perror("\nFailed to allocate space!");
        return;
    }

    for (int i = 0; i < 30; i++)
    {
        ptr[i] = i;
        printf("%d ", ptr[i]);
    }
    printf("\n\n");
    free(ptr);
}

void arrayFloat()
{
    float *ptr = (float *)malloc(5 * sizeof(float));
    if (ptr == NULL)
        return;
    float x = 0;
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = x += 1.6;
        printf("%.2f ", ptr[i]);
    }
    free(ptr);
}

void meCalloc()
{
    int n = 0;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    int *ptr = (int *)calloc(n + 1, sizeof(int)); // Allocates multiple blocks of zero initialized memory
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        printf("\nEntet value %d: ", i);
        scanf("%d", &x);
        ptr[i] = x;
    }
    for (int j = 0; j < n; j++)
    {
        printf("%d ", ptr[j]);
    }
    // printf("%d ", ptr[n+1]); // Cheking 0 value initialized by calloc
    free(ptr);
}

void meRealloc(){
    int *ptr = (int *) malloc(1 * sizeof(int));
    if(!ptr) return; 
    ptr[0] = 23;
    printf("\nBefore realloc: %d", ptr[0]);
    
    ptr = realloc(ptr, 3 * sizeof(int));
    ptr[1] = 2;
    ptr[2] = 3;
    printf("\nAfter realloc: %d, %d, %d", ptr[0], ptr[1], ptr[2]);
}

// Dynamically create an array of size 6
void q1(){
    int n = 0;
    int *ptr = (int *) calloc(6, sizeof(int));
    if(!ptr) return;
    for(int i = 0; i < 6; i++){
        printf("Enter value %d: ", i);
        scanf("%d", &n);
        ptr[i] = n;
    }
    printf("\nEntered values are:");
    for(int j = 0; j < 6; j++){
        printf("\n%d", ptr[j]);
    }
    free(ptr);
}

// Print data from array/ allocated memory
void printData(int* ptr, int n){
    for(int i = 0; i < n; i++){
        fprintf(stdout, "\n%d", ptr[i]);
    }
}

// Revision using realloc 
void q4(){
    int *ptr = (int *) calloc(5, sizeof(int));
    if(ptr == NULL) return;
    printData(ptr, 5);
    ptr = (int *) realloc(ptr, 10 * sizeof(int));
    ptr[5] = 7777777;
    printf("\n\nAfter");
    printData(ptr, 10);
    free(ptr);
}

void q5(){
    int *ptr = (int *) calloc(10, sizeof(int));
    if(ptr == NULL) return;
    for(int i = 1; i <= 10; i++){
        ptr[i] = i * 7;
        printf("\n%d", ptr[i]);
    }
    printf("\n\n");
    ptr = (int *) realloc(ptr, 15 * sizeof(int));
    for(int i = 1; i <= 15; i++){
        ptr[i] = i * 7;
        printf("\n%d", ptr[i]);
    }
}

// Fib sequence for filling array
void fib(unsigned long long *ptr1, int i)
{
    int first = ptr1[i - 2], second = ptr1[i - 1];

    ptr1[i] = first + second;
}

// Do not exceed 8byte numbers or else int overflow
void Fibo()
{

    int n;
    scanf("%d", &n);
    unsigned long long *ptr1;
    ptr1 = (unsigned long long *)malloc(n * sizeof(unsigned long long));

    // Initial values
    ptr1[0] = 0;
    ptr1[1] = 1;
    printf("\n\n%llu ", ptr1[0]);
    printf("%llu", ptr1[1]);

    for (int i = 2; i < n; i++)
    {
        fib(ptr1, i);
        printf(" %llu", ptr1[i]);
    }
    free(ptr1);
}

int main()
{

    // meAlloc();
    // Fibo();
    // arrayFloat();
    // meCalloc();
    // meRealloc();
    // q1();
    // q4();
    q5();

    return 0;
}