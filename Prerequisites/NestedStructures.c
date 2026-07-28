#include <stdio.h>
#include <windows.h>

// This structure carries the common properties of other structure.
struct Person
{
    char name[30];
    char email[20];
    int age;
    char address[100];
};

typedef struct Person Person;

// This structure holds the properties of Person to aviod redundancy.
struct Student
{
    Person p1;
    char collegeName[30];
    char course[20];
    float fees;
};

typedef struct Student Student;

int main()
{

    Student S1 = {
        {"Aditya Patel", "test@email.com", 21, "Prayagraj"},
        "BBS",
        "BCA",
        41000
    };

    printf("Name: %s\n", S1.p1.name);

    return 0;
}