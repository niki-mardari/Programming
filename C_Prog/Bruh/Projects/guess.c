#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(NULL)); // Seeding with current time
    int number = (rand() % 10) + 1;
    int guess = 0;
    int check;

    do{
    printf("\nGuess the number:");
    check = scanf("%d", &guess);
    if(check != 1){
        printf("\nEnter a valid number:");
        int c; // Cleaning buffer, removing characters until end of line 
        while(((c = getchar()) != '\n' && c != EOF));
        continue;
    }
    if(guess > number) printf("\nIt is lower than that!");
    else if(guess < number) printf("\nIt is higher than that!");
    else printf("\nCorrect! You Win!\n");
    } while(guess != number);

    return 0;
}