// Rle for 240 by 320 image

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>

// #define readFile "data/current.csv"
#define writeFile "rle_output.txt"
#define width 240
#define height 320

void rle(FILE* input, FILE* output){

    char* ptr; // To increment each char

    char line[2048]; // 2048 bytes to store each row, actually need 240*7 bytes for value and comma
    uint32_t count = 0;
    uint16_t current = -1; // Sentinel value
    uint16_t next;
    uint32_t pixels = 0;

    for(int row = 0; row < height; row++){
        fgets(line, sizeof(line), input);
        ptr = line;
        // Debugging
        // if(row == 100) break;

        for(int col = 0; col < width; col++){
            next = (uint16_t)strtol(ptr, &ptr, 16); // Parsing hex value, skipping comma
            ptr++; // To skip the comma location
            
            if(current == next){
            count++;
            }
            else{
                if(count > 0){
                    fprintf(output, "%x %d\n", current, count);
                    }
                    pixels += count;
                    current = next;
                    count = 1;
                }  
            }
        }
    // Reading last row because no next value 
    fprintf(output, "%x %d\n", current, count);
    pixels += count;
    printf("\nDone!\nThe pixel sum is: %d\n", pixels);
}

int main(int argc, char* argv[])
{
    if(argc < 2) perror("\nUsage: rle3.exe <filename>.txt");
    else{
    FILE* input = fopen(argv[1], "r");
    if(!input) return 1;

    FILE* output = fopen(writeFile, "w");
    if(!output) return 1;
    
    rle(input, output);
    
    fclose(input);
    fclose(output);

    }
    return 0;
}