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
    char newString[sizeof(string)];
    for(int i = m; i < n; i++){
        newString[i] = string[i];
        if(i == (n-1)) newString[i] = '\0';
    }
    printf("\nThe result is: %s", newString);
}

int main(){

    // learn();
    // q1();

    char s23[] = "Gafa";
    //printf("\nThe legth of Gafa is: %d",strlen2(s23));
    slice(s23, 1, 3);
    return 0;
}