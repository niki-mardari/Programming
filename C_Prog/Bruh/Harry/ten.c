// File IO

// A program lives in Ram and gets a stack to use for its variables in the ram, including stack frames for functions
// When the functions and the programme finishes, the data is lost if not explicitly saved to non volatile memory like NVM, separate Flash or EEPROM

#include <stdio.h>
#include <stdlib.h>

#define file "./samplefile.txt"

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
    FILE *ptr;
    ptr = fopen("./samplefile.txt", "w+");
    if (!ptr)
    {
        perror("Error opening the file!");
        return -1;
    }

    char str[] = "tHIS IS AMAZING!";
    fputs(str, ptr);
    rewind(ptr);

    if(fgets(str, 16, ptr) != NULL)
    {
        puts(str);
    }
    printf("The value of i is %s", str);

    fclose(ptr); // Force the file to close and clean up streams
    return 0;
}