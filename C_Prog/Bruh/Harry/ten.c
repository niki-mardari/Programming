// File IO

// A program lives in Ram and gets a stack to use for its variables in the ram, including stack frames for functions
// When the functions and the programme finishes, the data is lost if not explicitly saved to non volatile memory like NVM, separate Flash or EEPROM

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcat 

#define myFile "./samplefile.txt"

/*
void readFile(){

     FILE* source = fopen(file, "r+");
    // source = fopen("samplefile.txt", "r");
    if(!source) {
        perror("\nError opening the file!");
    }

    char ch;
    int i;

    // Reading a file
    fscanf(source, "%c", &ch);
    fscanf(source, "%d", &i);
    printf("\nThe first letter is: %c", ch);
    printf("\nThe first number is: %d", i);

    fclose(source); // Need to free it once done to release it
}
*/

/*
writeFile(){

    //FILE* source = fopen(file, "r+");
    // source = fopen("samplefile.txt", "r");
    //if(!source) {
    //    perror("\nError opening the file!");
    //}

    char ch;

    // Writing to a file
    //fprintf(source, "%d", i);

    // fgetc, fputc: used to read and write characters to/ from a file
    //fputc('c', source);
    //rewind(source); // Need to rewind because pointer increments once we put the character
    //ch = fgetc(source);
    printf("\n%c", ch);

    //fclose(source); // Need to free it once done to release it
}
*/
void wrString(char* file){
    FILE *ptr;
    ptr = fopen(file, "w+");
    if (!ptr)
    {
        perror("znError opening the file!");
        return;
    }

    char str[] = "\ntHIS IS AMAZING!\n";
    fputs(str, ptr);

    rewind(ptr);

    if(fgets(str, 16, ptr) != NULL)
    {
        puts(str);
    }

    printf("The string read is %s", str);

    fclose(ptr); // Force the file to close and clean up streams
}


void wrNumbers(char* file){
    FILE *ptr;
    ptr = fopen(file, "w+");
    if (!ptr)
    {
        perror("\nError opening the file!");
        return;
    }

    for(int i = 0; i < 5; i++){
        fprintf(ptr, "%d ", 12);
    }
    rewind(ptr);

    int x;

    while(fscanf(ptr, "%d ", &x) == 1)
        printf("\nNumber: %d", x);
    
    printf("\nThe value of i is %d", x);

    fclose(ptr); // Force the file to close and clean up streams
}

void writeMultiTable(char* file, int n){
    FILE* ptr = fopen(file, "a");
    if(!ptr){
        perror("\nError opening the file!");
        return;
    }
    printf("\n");
    for(int i = 1; i <= 12; i++){
        fprintf(ptr, "%d * %d = %d\n", i, n, i * n);
    }
    printf("\nDone!");
}

void copyFile(const char* file){
    FILE* source = fopen(file, "r");
    if(!source){
        perror("\nError opening the file!");
        return;
    }

    char* name = strcat("_copy.txt", file);

    FILE* copy = fopen(name, "w+");
    if(!copy){
        perror("\nError creating copy file!");
        return;
    }

    char ch;

    while((ch = fgetc(source)) != EOF)
        fprintf(copy, "%c", ch);
    
    fclose(source);
    fclose(copy);
}

int main()
{

    // readFile();
    // writeFile();

    /*
    FILE *ptr;
    ptr = fopen(file, "r");
    if(!ptr) {
        perror("\nError opening the file!");
        return -1;
    }

    int ch;
    while(1){

    ch = fgetc(ptr);
    if(ch != EOF) printf("\nThe value of ch is %c\n", (char)ch);
    else break;
    }
    fclose(ptr);
    */
    wrString(myFile);
    wrNumbers(myFile);
    writeMultiTable("./Tables.txt", 5);
    copyFile(myFile);

    return 0;
}