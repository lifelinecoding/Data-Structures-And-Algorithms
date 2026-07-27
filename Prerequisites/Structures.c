#include <stdio.h>
#include <windows.h>

struct Employee
{
    int age;
    float salary;
    char designation[30];
    char name[50];
    char companyName[50];
};

typedef struct Employee Employee;

void Print_Details(Employee args)
{
    printf("The name of the Employee: %s\n", args.name);
    printf("The age of the Employee: %d\n", args.age);
    printf("The salary of the Employee: %0.2f\n", args.salary);
    printf("The designation of the Employee: %s\n", args.designation);
    printf("The company name in which employee is working: %s\n", args.companyName);
}

int main()
{

    // Employee E1, E2, E3, E4, E5;

    Employee E1 = {20, 25000, "Software Engineer", "Aditya Patel", "HCLTech"};
    Employee E2 = {21, 52000, "QA Analyst", "Anand Singh", "Accenture"};
    Employee E3 = {23, 84000, "ML Engineer", "Priya Pal", "Infosys"};
    Employee E4 = {25, 19000, "Data Analyst", "Mohit", "Tech Mahindra"};
    Employee E5 = {31, 60000, "Automation", "Raj Sinha", "Cape Gemini"};

    Print_Details(E1);
    printf("\n");
    Print_Details(E2);
    printf("\n");
    Print_Details(E3);
    printf("\n");
    Print_Details(E4);
    printf("\n");
    Print_Details(E5);

    return 0;
}