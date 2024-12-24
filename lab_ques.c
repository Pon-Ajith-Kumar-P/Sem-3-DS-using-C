#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student 
{
    int roll;
    char name[50];
    char grade;
    struct Student* next;
} Student;

Student* create(int roll, char* name, char grade) 
{
    Student* new = (Student*)malloc(sizeof(Student));
    new->roll = roll;
    strcpy(new->name, name);
    new->grade = grade;
    new->next = NULL;
    return new;
}

Student* add(Student* list, int roll, char* name, char grade) 
{
    Student* new = create(roll, name, grade);
    
    if (list == NULL) 
    {
        return new;
    } 
    
    Student* temp = list;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = new;
    
    return list;
}

void display(Student* list) 
{
    Student* temp = list;
    if (temp == NULL) 
    {
        printf("No students to display.\n");
        return;
    }
    while (temp != NULL) 
    {
        printf("Roll No. : %d\nName: %s\nGrade: %c\n", temp->roll, temp->name, temp->grade);
        temp = temp->next;
    }
}

Student* delete(Student* list, int roll) 
{
    Student* temp = list;
    Student* prev = NULL;

    if (temp != NULL && temp->roll == roll) 
    {
        list = temp->next;
        free(temp);
        printf("Student with Roll %d deleted.\n", roll);
        return list;
    }

    while (temp != NULL && temp->roll != roll) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Student with Roll %d not found.\n", roll);
        return list;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student with Roll %d deleted.\n", roll);
    
    return list;
}

void find(Student* list, char* name) 
{
    Student* temp = list;
    while (temp != NULL) 
    {
        if (strcmp(temp->name, name) == 0) 
        {
            printf("Roll No. : %d\nGrade: %c\n", temp->roll, temp->grade);
            return;
        }
        temp = temp->next;
    }
    printf("Student with Name %s not found.\n", name);
}

int main() 
{
    Student* list = NULL;
    int choice, roll;
    char name[50];
    char grade;

    do 
    {
        printf("\n1. Add a Student");
        printf("\n2. Display All Students");
        printf("\n3. Delete a Student");
        printf("\n4. Find a Student by Name");
        printf("\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter Roll: ");
                scanf("%d", &roll);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Grade: ");
                scanf(" %c", &grade);
                list = add(list, roll, name, grade);
                break;
            case 2:
                display(list);
                break;
            case 3:
                printf("Enter Roll to delete: ");
                scanf("%d", &roll);
                list = delete(list, roll);
                break;
            case 4:
                printf("Enter Name to search: ");
                scanf("%s", name);
                find(list, name);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}