#include <stdio.h>
#include <windows.h>

// Structure definition
struct Student
{
    int age;
    float fees;
    char course[30];
    char name[50];
    char collegeName[50];
    char contact[15];
    char email[25];
};

// Type definition
typedef struct Student Student;

// Create a fucntion to take the input from the user and store it into the structure Objects (Array).

void TakeUserInput(Student arr[], int index)
{

    for (int i = 0; i < index; i++)
    {
        printf("\n\n");

        printf("Enter the name of the student: ");
        fgets(arr[i].name, sizeof(arr[i].name), stdin);

        printf("Enter the course of the student: ");
        fgets(arr[i].course, sizeof(arr[i].course), stdin);

        printf("Enter the college name: ");
        fgets(arr[i].collegeName, sizeof(arr[i].collegeName), stdin);

        printf("Enter the contact of the student: ");
        fgets(arr[i].contact, sizeof(arr[i].contact), stdin);

        printf("Enter the email of the student: ");
        fgets(arr[i].email, sizeof(arr[i].email), stdin);

        printf("Enter the course fees of the student: ");
        scanf("%f", &arr[i].fees);

        printf("Enter the age of the student: ");
        scanf("%d", &arr[i].age);

        getchar();
    }
}

// Create a fucntion to display  the user data stored into the structure Objects (Array).
void PrintStudentDetails(Student *arr, int index)
{

    for (int i = 0; i < index; i++)
    {
        printf("\n\n");

        printf("The name of the student is: %s", arr[i].name);
        printf("The age of the student is: %d\n", arr[i].age);
        printf("The fees of the student is: %0.2f\n", arr[i].fees);
        printf("The course of the student is: %s", arr[i].course);
        printf("The college name is: %s", arr[i].collegeName);
        printf("The contact number of the student is: %s", arr[i].contact);
        printf("The email of the student is: %s", arr[i].email);
    }
}

int main()
{

    Student arr[5];
    int index = sizeof(arr) / sizeof(arr[0]);

    TakeUserInput(arr, index);
    printf("\n\n"); // Taking two line space

    PrintStudentDetails(arr, index);

    return 0;
}