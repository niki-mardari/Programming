// File IO

// A program lives in Ram and gets a stack to use for its variables in the ram, including stack frames for functions
// When the functions and the programme finishes, the data is lost if not explicitly saved to non volatile memory like NVM, separate Flash or EEPROM

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcat

#define myFile "samplefile.txt"

void writeFile(char *file)
{

    FILE *source = fopen(file, "w+");
    if (!source)
    {
        perror("\nError opening the file!");
        return;
    }

    // Writing to a file
    fprintf(source, "%d", 23);
    fprintf(source, "%c", 'A');

    // fgetc, fputc: used to read and write characters to/ from a file
    fputc('C', source);

    fclose(source); // Need to free it once done to release it
}

void readFile(char *file)
{

    FILE *source;
    source = fopen(file, "r+");
    if (!source)
    {
        perror("\nError opening the file!");
    }

    char ch;
    // int i;

    printf("\nReading letters:\n");
    // Reading letters in a file
    while (!feof(source))
    {
        // fscanf(source, "%d", &i);
        // fscanf(source, "%c", &ch);
        ch = fgetc(source);
        printf("%c", ch);
    }

    // printf("\nThe first number is: %d", i);
    // printf("\nThe first letter is: %c", ch);

    fclose(source); // Need to free it once done to release it
}

void wrString(char *file)
{
    FILE *ptr;
    ptr = fopen(file, "w+");
    if (!ptr)
    {
        perror("\nError opening the file!");
        return;
    }

    char str[] = "tHIS IS AMAZING!\n";
    char buffer[100];
    fputs(str, ptr);

    rewind(ptr);

    while (fgets(buffer, sizeof(buffer), ptr) != NULL)
    {
        printf("\nThe string read is: ");
        puts(buffer);
    }

    fclose(ptr); // Force the file to close and clean up streams
}

void wrNumbers(char *file)
{
    FILE *ptr;
    ptr = fopen(file, "w+");
    if (!ptr)
    {
        perror("\nError opening the file!");
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        fprintf(ptr, "%d ", 12);
    }
    rewind(ptr);

    int x;

    while (fscanf(ptr, "%d ", &x) == 1)
        printf("\nNumber: %d", x);

    printf("\nThe value of i is %d", x);

    fclose(ptr); // Force the file to close and clean up streams
}

void writeMultiTable(char *file, int n)
{
    FILE *ptr = fopen(file, "a");
    if (!ptr)
    {
        perror("\nError opening the file!");
        return;
    }
    printf("\n");
    for (int i = 1; i <= 12; i++)
    {
        fprintf(ptr, "%d * %d = %d\n", i, n, i * n);
    }
    printf("\nDone!");
}

void insertChar(char *s, char *c, char *res)
{
    int length = strlen(s);
    // int* ptr = s;
    int j = 0;
    int ext_found = 0;

    for (int i = 0; i < length; i++)
    {
        // If dot then add new characters
        if ((s[i]) == '.' && !ext_found)
        {
            int k = 0;
            while (c[k] != '\0')
            {
                res[j++] = c[k++];
            }
            ext_found = 1;
        }

        // Insert original characters
        res[j++] = s[i];
    }

    // If there was no dot extension in the filename, append it at the end
    if (!ext_found)
    {
        int k = 0;
        while (c[k] != '\0')
        {
            res[j++] = c[k++];
        }
    }

    res[j] = '\0'; // Null-terminate string
}

void copyFile(char *file)
{
    FILE *source = fopen(file, "r");
    if (!source)
    {
        perror("\nError opening the file!");
        return;
    }

    char name[64] = "_copy";
    char resultant[64];

    // strcat(name, file);
    // printf("\n%s", name);

    insertChar(file, name, resultant);
    printf("\n%s", resultant);

    FILE *copy = fopen(resultant, "w");
    if (!copy)
    {
        perror("\nError creating copy file!");
        return;
    }

    int ch;

    while ((ch = fgetc(source)) != EOF)
        fprintf(copy, "%c", ch);

    fclose(source);
    fclose(copy);
}

void employeeSpreadsheet()
{

    struct employee
    {
        char name[50];
        int salary;
    };

    struct employee employees[2];
    // Clear the entire block of memory allocated for the array to 0
    memset(employees, 0, sizeof(employees));

    // emp man1; // Ask if I can initialize it from user input !
    // emp man2;

    scanf("%49s %d", employees[0].name, &(employees[0].salary));
    scanf("%49s %d", employees[1].name, &(employees[1].salary));

    FILE *ptr = fopen("employee_spreadsheet.txt", "w");
    if (!ptr)
    {
        perror("\nError creating file!");
        return;
    }
    // char* names = {"man1","man2"};
    for (int i = 0; i < 2; i++)
    {
        // fputs(employees[i].name, ptr);
        // fputs(", ", ptr);
        // fprintf(ptr, "%d\n", employees[i].salary);
        fprintf(ptr, "%s, %d\n", employees[i].name, employees[i].salary);
    }
    fclose(ptr);
}

void doubleVal(char *file)
{
    FILE *ptr = fopen(file, "w+");
    if (!ptr)
    {
        perror("\nError opening the file!");
        return;
    }
    int x;
    while (fscanf(ptr, "%d ", &x) == 1)
        printf("\nNumber: %d", x);

    x *= 2;

    rewind(ptr);

    fprintf(ptr, "%d ", x);

    fclose(ptr); // Force the file to close and clean up streams
}

int main()
{
    writeFile("example.txt");
    readFile("example.txt");
    wrString(myFile);
    wrNumbers(myFile);
    writeMultiTable("./Tables.txt", 5);
    copyFile(myFile);

    employeeSpreadsheet();

    doubleVal("number.txt");

    return 0;
}