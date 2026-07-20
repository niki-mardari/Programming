#include<stdio.h>
#include<stdlib.h>

void myArray(){
    int array[20];

    for(unsigned int i = 0; i < 20; i++){
        array[i] = i + 3;
    }

    for(unsigned int j = 0; j < sizeof(array)/sizeof(int); j++){
        printf("\n%d", array[j]);
    }
}

void grades(){

    int* grades = NULL;
    unsigned int students;

    printf("\nEnter amount of students: ");
    int check = scanf("%d", &students);
     if (check != 1){
            printf("\nEnter a valid number:");
            int c; // Cleaning buffer, removing characters until end of line 
            while((c = getchar() != '\n' && c != EOF));
    }

    grades = malloc(students * sizeof(int));

    for(unsigned int i = 0; i < students; i++){
        printf("\nEnter the grade for student %d : ", i + 1);
        int check = scanf("%d", &grades[i]);
            if (check != 1){
                printf("\nEnter a valid number:");
                int c; // Cleaning buffer, removing characters until end of line 
                while((c = getchar() != '\n' && c != EOF));
                }
            if(grades[i] > 100 || grades[i] < 0){
                printf("\nGrade must be within 0 - 100\nEnter it again!\n");
                grades[i] = '\0';
                i--;      
            }
            continue;
        }

        printf("\nThe details entered are:\n");
        for(unsigned int i = 0; i < students; i++){
            printf("Student %d: %d\n", i + 1, grades[i]);
        }
        free(grades);
    }

int main(){

    myArray();
    grades();

    return 0;
}