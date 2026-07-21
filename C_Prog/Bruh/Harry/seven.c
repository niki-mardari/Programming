#include <stdio.h>
#include <stdlib.h>

// Populating an array
void myArray()
{
    int array[20];

    for (unsigned int i = 0; i < 20; i++)
    {
        array[i] = i + 3;
        printf("\n%d", array[i]);
    }
}

// Grades logger
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
        printf("%c\n", *array);
        array ++;
    }
}

void q0(){
    int marks[2][4] = {{98, 93, 83, 99},{38, 63, 43, 68}};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", marks[i][j]);
        }
        printf("\n");
    }
}

void q1(){
    int numbers[] = {1,2,3,4,5,6,7,8,9,10};
    size_t n = sizeof(numbers) / sizeof(int);
    int* ptr = numbers;
    for(int i = 0; i < (int)n; i++){
        printf("\n%d", numbers[i]);
    }
    ptr = ptr + 2;
    printf("\n3rd element is %d\n", *ptr);
}

void q2(){
    int multiples[10];
    int value = 0;
    size_t n = sizeof(multiples) / sizeof(int);
    int check = 0;
    do{
    check = scanf("%d", &value);
    // if(check != 1){
        printf("Invalid Number!\n");
        int c;
        while(((c = getchar()) != '\n' && c != EOF));
    } while(check != 1);
    for(int i = 1; i < (int)n + 1; i++){
        multiples[i] = value * i;
        printf("\n%d * %d = %d", i, value, multiples[i]);
    }
}

void q3(int* ptr){

    int new_array[3];
    for(int i = 2; i >= 0; i--){
        // int dest = 2 - i;
        printf("\n%d ", *(&ptr[2 - i]));
        //*ptr++;
        new_array[2 - i] = *(&ptr[i]);
        printf("%d ", new_array[2 - i]);
    }
    printf("\n");
}
////////////////////////////////////////////////
void reverse(int* ptr, int n){
    for(int i = 0; i < n/2; i++){
        int temp = ptr[i];
        ptr[i] = ptr[n - i - 1];
        ptr[n - i - 1] = temp;
        // Swap 0 with n - 1
        // Swap 1 with n - 2
        // Swap 2 with n - 3
    }
}

void display(int* ptr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}
////////////////////////////////////////////////

// Counting positive numbers in an array
void q6(int* ptr, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(ptr[i] >= 0) count++;
    }  
    printf("\nThe total positive integers is %d out of %d\n", count, n); 
}

void q7(){
    int arr[3][10];
    int x[3] = {2,5,7};
    //int* ptr = x;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            arr[i][j] = x[i] * j+1;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    //char array[] = "\nBye!";

    //myArray();
    //grades();
    //myFunc(array);

    //q0();
    //q1();
    //q2();

    int array2[3] = {1,2,3};
    int* ptr = array2;
    q3(ptr);

    int arr[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    display(arr, 10);
    reverse(arr, 10);
    display(arr, 10);

    q6(arr, 10);
    q7();

    return 0;
}