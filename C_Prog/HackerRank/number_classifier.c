// Must tell whether number is positive, negative or zero 

// Must tell whether it is even or odd

#include <stdio.h>
#include <stdlib.h> // For atoi 
#include <stdint.h> // For int32_t 
#include <string.h> // For memset

int main(int argc, char* argv[]){
    if(argc != 2) return 0;

        enum Sign {
            POSITIVE, // 0
            NEGATIVE, // 1
            ZERO      // 2
        };

        enum Type {
            EVEN, // 0
            ODD   // 1
        };

        int32_t n = atoi(argv[1]);
        // int32_t sign, type; // type for even or odd
        const char *signText; // Pointer for sign string 
        const char *typeText; // Pointer for type string (Even or Odd) 

        enum Sign mySign;
        enum Type myType;

        if(n > 0) mySign = POSITIVE; 
        else if(n < 0) mySign = NEGATIVE; 
        else { mySign = ZERO; }

        // Check if bit 0 is set
        // If bit 0 remains 1 then ODD, if 1 then EVEN
        if(n & 1U) myType = ODD; 
        else { myType = EVEN; }

        // If type is 0 then even if type is 1 then odd 
        // printf("\nThe number sign is: %d and type is: %d", mySign, myType);
        switch (mySign) {
            case POSITIVE: signText = "positive\0";
            break;
            case NEGATIVE: signText = "negative\0";
            break;
            case ZERO: signText = "zero\0";
            break;
            default: signText = "unknown\0";
        }

        switch (myType){
            case EVEN: typeText = "even\0";
            break;
            case ODD: typeText = "odd\0";
            break;
        }

        printf("\nThe number is %s and %s", signText, typeText);

    return 0; 
}


// Another way is to think in states:
// Separate decision and action 
// Useful in embedded systems where the results are not displayed in terminal but on a screen
// Or other peripheral like buzzer or led

/*

#include <stdio.h>
#include <stdlib.h> // For atoi 

int main(int argc, char* argv[]){
    if(argc != 2) return 0;

        int n = atoi(argv[1]);
        if(n == 0) printf("\nThe number is zero!");
        else if (n > 0) printf("\nThe number is positive");
        else {printf("\nThe number is negative");}
        if((n % 2) != 0) printf("\nThe number is odd");
        else {printf("\nThe number is even");}


    return 0; 
}

*/