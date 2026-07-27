// Revising Strings 
#include<stdio.h>
#include<string.h> // For string manipulation 
// strlen, strcpy, strcat
#include<stdlib.h>

void learn(){
    
    // Creating a string 
    char name[] = {'N', 'I', 'C', 'K', '\0'};
    // Or just do this: char name[] = "Nick";
    fprintf(stdout, "\nName: %s\n", name);

    // Accepting a string as input 
    //scanf("%s", name);
    //fprintf(stdout, "\nName: %s\n", name);

    // gets/ puts used when string has multiwords with space 
    // gets(name);
    // puts(name);

    // Declare string using pointer 
    // When a string is initialized, it cannot be changed (Immutable) eg: char name[] = "Jimmy";
    // Can change a string using pointers 

    fprintf(stdout, "\nLength: %lld\n", strlen(name));

    // strcpy used to copy strings
    char source[] = "Jack";
    char target[20];
    strcpy(target, source);
    printf("\n%s\n", target);

    // strcat used to concatenate strings 
    char s1[] = "Hello,";
    char s2[] = "World!";
    strcat(s1, s2);
    // Stores in s1
    printf("\n%s", s1);

    // strcmp is used to compare strings 
    // Must use pointers! Cannot use char s3[] = "Bobby";
    printf("\nDiff: %d", strcmp(source, name));
}

void q1(){
    char s1[20];
    char* ptr = s1;

    printf("\nEnter 4 letter characters each time:\n");
    for(int i = 0; i < 4; i++){
        scanf(" %c", ptr);
        // fflush(stdin); didnt work added a space before specifier %c to ignore newline
        ptr++;
    }

    // 3. Properly null-terminate the string
    *ptr = '\0'; 

    for(int j = 0; j < 4; j++){
        printf("%c", s1[j]);
    }
    printf("\nComparing this string with NIKI gives: %d", strcmp("Nick", s1));
}

int strlen2(char* word){
    char* ptr = word;
    int count = 0;
    
    while(*ptr != '\0'){
        count++;
        ptr++;
    }
    return count;
}

void slice(char* string, int m, int n){
    char newString[strlen(string)+1]; // sizof was calculating the size of the pointer 
    for(int i = m; i < n; i++){
        newString[i-m] = string[i];
        if(i == (n-1)) newString[i] = '\0';
    }
    printf("\nThe result is: %s", newString);
}

/* 
// Need to work on this, returns a local string, it gets removed from the stack frame once the function is over
char *slice2(char* string, int m, int n){
    int sliceLength = n - m;
    char newString[sliceLength - 1];

    int j = 0;
    for(int i = m; i < n; i++){
        newString[j] = string[i];
        j++;
    }
    newString[j] = '\0';

    // printf("\nThe result is: %s\n", newString);
    return newString;
}
*/

/*
void slice3(char* string, int m, int n){
    // Take string 
    // slice it and save it in the original string
    // Say string is 'G' , 'A' , 'F' , 'A' , '\0'
    // Input Gafa, 0, 2 
    // Should return GAF
}
*/

void myStrcpy(char* dest, char* source){
    size_t totalSize = strlen(source);
    for(size_t i = 0; i < totalSize; i++){
        dest[i] = source[i];
    }
    printf("\n\n%s", dest);
}

void encrypt(char* message){
    size_t length = strlen(message);
    for(size_t i = 0; i < length; i++){
        message[i] ++; 
    }
    printf("\nEncrypted message: %s", message);
} 

void decrypt(char* message){
    size_t length = strlen(message);
    for(size_t i = 0; i < length; i++){
        message[i] --;
    }
    printf("\nDecrypted message: %s", message);
} 

void findOccurence(char* string, char target){
    size_t length = strlen(string);
    int count = 0;
    for(size_t i = 0; i < length; i++){
        if(string[i] == target) count++;
    }
    printf("\nThe letter %c occured %d times", target, count);
}

void isPresent(char* string, char target){
    size_t length = strlen(string);
    int found = 0;
    for(size_t i = 0; i < length; i++){
        if(string[i] == target){
            found = 1;
            break;
        }
    }
    printf("\n%c is %s in string %s\n", target, found == 1 ? "present" : "Not present", string);
}

int main(){

    // learn();
    // q1();

    char s23[] = "Gafa";
    //printf("\nThe legth of Gafa is: %d",strlen2(s23));
    slice(s23, 0, 6);
    //char test[] = "Hello World";
    //slice2(test, 6, 11);
    //char* newString = slice2(test, 6, 11);
    //printf("\nThe result is: %s\n", newString);
    char dest[] = "Faga";
    myStrcpy(s23, dest);

    char message[] = "Password";
    encrypt(message);
    decrypt(message);

    isPresent(s23, 'a');


    return 0;
}