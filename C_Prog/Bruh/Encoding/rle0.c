// Basic RLE of a 256 by 256 image

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>

#define readFile "data/current.csv"
//#define writeFile "data/output.txt"
//#define width 240
//#define height 320

int main()
{
    FILE* input = fopen(readFile, "rb");
    if(!input) return 1;

    char* ptr; // To increment each char

    char line[2048]; // 32 Bytes in 256 bits // 120 in 240 hex numbers
    int count = 0;
    uint16_t current = -1; // Sentinel value
    uint16_t next;

    for(int row = 0; row < 320; row++){
        fgets(line, sizeof(line), input);
        ptr = line;
        // Debugging
        // if(row == 2) break;

        for(int col = 0; col < 240; col++){
            next = (uint16_t)strtol(ptr, &ptr, 16); // Parsing hex value, skipping comma
            ptr++; // To skip the comma location
            
            if(current == next) count++;
            else{
                if(count > 0){
                    fprintf(stdout, "%d %d\n", current, count);
                    current = next;
                    count = 1;
                    }
                }  
            }
        }
    fprintf(stdout, "%d %d\n", current, count);
    fclose(input);

    return 0;
}