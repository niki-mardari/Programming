#include<stdio.h>
#include<string.h>

// Need to read hex values 
// Need to parse commas 

// RLE funciton 
void rle(FILE* input, FILE* output){
    //int current, next, count = 1;
    int count = 1;
    char* next_ptr;
    // Parsing string into hex
    unsigned int current = (unsigned int)strtol(input, &next_ptr, 16);

    // If first read char is \0, then stop
    if((current = fgetc(input)) == EOF) return;
    
    // Keep reading while there is something to read
    while((next = getc(input)) != EOF){
        if(next == current) count++;
        else {
            fputc(current, output);
            if(count > 1) fprintf(count, "%d",  output);
            
            current = next;
            count = 1;
        }
    }
    fputc(current, output);
    if(count > 1) fprintf(count, "%d",  output);
}

int main(int argc, char* argv[]){

    if(argc < 2) perror("\nUsage: rle.exe <filename>.txt");
    else{
        FILE* input;
        input = fopen(argv[1], "r");
        if (input == NULL) perror("\nFile not opened!");

        FILE* output;
        output = fopen("rle_test.txt", "w");
        if (output == NULL) perror("\nFile not created!");

        rle(input, output);
        
        fclose(input);
        fclose(output);
    }
    
    return 0;
}