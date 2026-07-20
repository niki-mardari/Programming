#include <stdio.h>
#include <stdlib.h>

void myArray()
{
    int array[20];

    for (unsigned int i = 0; i < 20; i++)
    {
        array[i] = i + 3;
    }

    for (unsigned int j = 0; j < sizeof(array) / sizeof(int); j++)
    {
        printf("\n%d", array[j]);
    }
}

void grades()
{

    int *grades = NULL;
    int students;

    do
    {
        printf("\nEnter amount of students: ");
        int check = scanf("%d", &students);
        if (check != 1)
        {
            printf("\nEnter a valid number:");
            int c; // Cleaning buffer, removing characters until end of line
            while (((c = getchar()) != '\n' && c != EOF))
                ;
        }
        if (students <= 0)
        {
            printf("\nCannot be less than 0 students!\n");
            continue;
        }
    } while (students < 1);

    grades = malloc(students * sizeof(int));

    for (int i = 0; i < students; i++)
    {
        printf("\nEnter the grade for student %d : ", i + 1);
        int check = scanf("%d", &grades[i]);
        if (check != 1)
        {
            printf("\nEnter a valid number:");
            int c; // Cleaning buffer, removing characters until end of line
            while (((c = getchar()) != '\n' && c != EOF))
                ;
        }
        if (grades[i] > 100 || grades[i] < 0)
        {
            printf("\nGrade must be within 0 - 100\nEnter it again!\n");
            grades[i] = '\0';
            i--;
        }
    }

    // Pointer to elements in grades array
    int *ptr = grades;
    if (students <= 1)
    {
        *ptr = 77;
    }
    else
    {
        ptr++; // Increments location by 4 bytes (an integer size)
        *ptr = 77;
    }

    printf("\nThe details entered are:\n");
    for (int i = 0; i < students; i++)
    {
        printf("Student %d: %d\n", i + 1, grades[i]);
    }
    free(grades);
}

// Passing arrays to functions 
void myFunc(char *array){
    for(int i = 0; i < 3; i++){
        *array = 'K';
        printf("%c", *array);
        array ++;
    }
}

int main()
{
    char array[] = "\nBye!";

    myArray();
    grades();
    myFunc(array);

    return 0;
}