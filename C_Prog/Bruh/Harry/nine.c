// Structures in c programming
// Useful in OOP (Object Oriented Programming)
// Encapsulation - Bundling data and hiding internal state
// Polymorphism - Allowing objects to take different forms
// Abstraction - Exposing only essential features and hiding inner workings
// Inheritance - Reusing and extending code

// Essentially a structure bundles data in a collection
// Allows to group different types

// Array Structures are stored in continuous memory so the address are next to each other
#include <stdio.h>
#include <string.h>

struct employee
{
    int salary;
    float performance;
    char name[10];
};

// Function for demonstating how structs are passed into functions
void showStruct(struct employee* e){
    (*e).name[0] = 'S';
    printf("\nRunning showStruct func: \n%s, %f, %d", e->name, e->performance, e->salary);
}

typedef struct vector{
    float mag;
    float direc;
} vec;

vec sum(vec first, vec second){
    int a, b;
    a = first.mag + second.mag;
    b = first.direc + second.direc;
    vec result = {a, b}; 

    return result;
}

    // Type def keyword 
    // Used to create an alias or datatypes in c 
    typedef struct imagiaryNumber{
        int real;
        int imag;
    } no;

void showComplexNo(no* e){
    printf("\nFirst imaginary number: %d + %dj", e[0].real, e[0].imag);
    printf("\nSecond imaginary number: %d + %dj", e[1].real, e[1].imag);
}

typedef struct date{
    int day;
    int month;
    int year;
} date;

void compareDate(date d1, date d2){
    int day, month, year;

    // Need to check which one is larger 
    // Limit days to the appropriate days in month
    // Have a limit of maximum 12 months 
    day = d2.day - d1.day;
    month = d2.month - d1.month;
    year = d2.year - d1.year;
    if(d1.year > d2.year || d1.month > d2.month || d1.day > d2.day) printf("\nd1 will come first");
    else printf("\nd2 will come first");
    printf("\nDifference is %d days , %d months, %d years", day, month, year);
}

int main()
{

    // Normal struct
    struct employee nick;
    nick.salary = 50000;
    nick.performance = 0.67;
    strcpy(nick.name, "Jm7");
    printf("\n%d", nick.salary);
    printf("\n%f", nick.performance);
    printf("\n%s", nick.name);

    // array of structs
    struct employee employees[10];
    employees[0].salary = 50000;
    employees[0].performance = 0.67;
    strcpy(employees[0].name, "Sheer");
    printf("\nEmployee 1 stats: \n%s, %f, %d", employees[0].name, employees[0].performance, employees[0].salary);

    // Initializing a structure
    struct employee jimbob = {34, 5.2, "JimBob"};
    // struct employee jimbob = {0}; // Sets all elements to 0
    printf("\nEmployee Example stats: \n%s, %f, %d", jimbob.name, jimbob.performance, jimbob.salary);

    // Structure pointers
    struct employee *ptr;
    ptr = &jimbob; // Pointer of type employee
    printf("\n%s is the best!", (*ptr).name);

    // Arrow operator
    // Instead of using the (*ptr).name can use arrow operator
    // Easier to read and maintain
    printf("\n%d is earned", ptr->salary);

    // Passing structure to a function
    showStruct(ptr);

    no alpha = {50, 90};
    printf("\nAlpha imaginary number: %d + %dj", alpha.real, alpha.imag);

    //------------------ Practice: ------------------//
    vec v1 = {40, 50}, v2 = {60, 90};
    // Can also do it like this:
    // v2.direc = 60;
    // v2.mag = 90;
    printf("\nVector 1: %.2f, %.2f\nVector 2: %.2f, %.2f", v1.mag, v1.direc, v2.mag, v2.direc);

    // Summing the two vectors 
    vec v3 = sum(v1, v2);
    printf("\n\nThe sum of v1 and v2 is: %.2f, %.2f", v3.mag, v3.direc);

    // Using arrow operator
    struct animal{
        int quantity;
        char name[10];
    };

    struct animal cat = {4, "Weena"};
    struct animal *ptr2 = &cat; 
    printf("\n\n%s is the best cat in the world! It has %d limbs!", ptr2->name, ptr2->quantity);

    // Array of complex numbers 
    no array[2];
    for(int i = 0; i < 2; i++){
    scanf("%d", &array[i].real);
    scanf("%d", &array[i].imag);
    }
    no *ptr3 = array;
    showComplexNo(ptr3);

    date d1 = {31, 12, 2024};
    date d2 = {01, 01, 2025};
    compareDate(d1, d2);
    return 0;
}