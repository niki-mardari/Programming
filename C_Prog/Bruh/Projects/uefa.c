#include <stdio.h>
#include <stdlib.h> // For rand function
#include <time.h>   // For time

// Rock beats Scissors
// Paper beats Rock
// Scissors beats paper

int whoWon(char you, char comp)
{
    if (you == comp)
        return 0;
    else if ((you == 'R' && comp == 'P') || (you == 'P' && comp == 'S') || (you == 'S' && comp == 'R'))
        return 1;
    else
        return -1;
}

int main()
{

    srand(time(NULL)); // Seeding with current time
    char you, comp;
    int valid = 0; // For checking if input is correct
    int c; // For clearing stdin buffer

    do
    {
        fprintf(stdout, "\nRock (R), Paper (P) or Scissors (S)\n");
        if (scanf("%c", &you) == 1)
        {
            // Check if the character is strictly R, P, or S
            if (you == 'R' || you == 'P' || you == 'S')
            {
                valid = 1;
            }
            else
            {
                printf("Invalid choice! Numbers and unlisted letters are not allowed.\n");
            }
        }  while ((c = getchar()) != '\n' && c != EOF);
    } 
    while(!valid);

    char choices[3] = {'R', 'P', 'S'};
    int number = (rand() % 2) + 1;
    comp = choices[number];

    int result = whoWon(you, comp);
    if (result == 0)
        printf("\nGame Draw!");
    else if (result == 1)
        printf("\nComputer Won");
    else
        printf("\nYou Won!");

    printf("\nYou chose %c and computer chose %c\n", you, comp);

    return 0;
}