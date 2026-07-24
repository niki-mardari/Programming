#include<stdio.h>
#include<stdlib.h> // For rand function
#include<time.h> // For time

// Rock beats Scissors
// Paper beats Rock
// Scissors beats paper

int whoWon(char you, char comp){
    if(you == comp) return 0;
    else if((you == 'R' && comp == 'P') || (you == 'P' && comp == 'S') || (you == 'S' && comp == 'R')) return 1;
    else return -1;
}

int main(){

    srand(time(NULL)); // Seeding with current time

    fprintf(stdout, "\nRock (R), Paper (P) or Scissors (S)\n");
    char you, comp;
    scanf("%c", &you);

    char choices[3] = {'R','P','S'};
    int number = (rand() % 3) + 1;
    comp = choices[number];

    int result = whoWon(you, comp);
    if(result == 0) printf("\nGame Draw!");
    else if(result == 1) printf("\nComputer Won");
    else printf("\nYou Won!");

    printf("\nYou chose %c and computer chose %c\n", you, comp);

    return 0;
}