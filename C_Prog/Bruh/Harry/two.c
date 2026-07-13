#include<stdio.h>

void grade(int a, int b, int c){
    //int subjects = sizeof(grades) / sizeof(100);
    float finalGrade = a + b + c / 3;
    char* pass = (finalGrade > 40) ? "Pass":"Fail";
    printf("The final decision is: %s\n", pass);
}

void leapYear(int x){
    char* decision = (x%4 != 0 && x%100 != 0 && x%400 != 0) ? "Not leap year\n" : "Is leap year\n";
    fprintf(stdout, "\n%s", decision);
}

void lowerCase(char character){
    char* lower = (character >= 97 && character <= 122) ? "Lower case\n" : "Upper case\n";
    fprintf(stdout, "\n%s", lower);
}

void largest(int a, int b, int c, int d){
    int strongest = 0;
    if(a > b && a > c && a > c && a > d){
        strongest = a; 
    } else if(b > a && b > c && b > d){
        strongest = b;
    } else if(c > a && c > b && c > d){
        strongest = c;
    } else if(d > a && d > b && d > c){
        strongest = d;
    } fprintf(stdout, "\nThe largest is: %d\n", strongest);
}

int main(){
    int a, b ,c, year;
    scanf("%d %d %d", &a, &b, &c);
    grade(a, b, c);
    scanf("%d", &year);
    leapYear(year);
    lowerCase('A');
    largest(1,2,3,4);
    return 0;
}