#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BookNode 
{
    int bookID;
    char title[100];
    char author[100];
    struct BookNode* prev;
    struct BookNode* next;
} BookNode;

BookNode* head = NULL;

BookNode* createBookNode(int id, char* title, char* author) 
{
    BookNode* newNode = (BookNode*)malloc(sizeof(BookNode));
    newNode->bookID = id;
    strncpy(newNode->title, title, sizeof(newNode->title) - 1);
    strncpy(newNode->author, author, sizeof(newNode->author) - 1);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBook(int id, char* title, char* author) 
{
    BookNode* newNode = createBookNode(id, title, author);

    if (head == NULL) 
    {
        head = newNode;
        return;
    }

    if (id < head->bookID) 
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    BookNode* current = head;
    while (current->next != NULL && current->next->bookID < id) 
    {
        current = current->next;
    }

    if (current->next == NULL) 
    {
        current->next = newNode;
        newNode->prev = current;
    } 
    else 
    { 
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void deleteBook(int id) 
{
    BookNode* current = head;

    while (current != NULL && current->bookID != id) 
    {
        current = current->next;
    }

    if (current == NULL) 
    {
        printf("Book with ID %d not found.\n", id);
        return;
    }
    if (current->prev != NULL) 
    {
        current->prev->next = current->next;
    } 
    else 
    { 
        head = current->next;
    }

    if (current->next != NULL) 
    {
        current->next->prev = current->prev;
    }
    free(current);
    printf("Book with ID %d deleted.\n", id);
}

void displayBooks() 
{
    BookNode* current = head;

    printf("Books in forward order:\n");
    while (current != NULL) 
    {
        printf("ID: %d, Title: %s, Author: %s\n", current->bookID, current->title, current->author);
        current = current->next;
    }

    current = head;

    printf("Books in reverse order:\n");
    while (current != NULL) 
    {
        current = current->next;
    }
    while (current != NULL) 
    {
        printf("ID: %d, Title: %s, Author: %s\n", current->bookID, current->title, current->author);
        current = current->prev;
    }
}

void deallocateList() 
{
    BookNode* current = head;
    BookNode* newNode;

    while (current != NULL) 
    {
        newNode = current->next;
        free(current);
        current = newNode;
    }

    head = NULL;
}
int main() 
{
    int choice, id;
    char title[100], author[100];

    while (1) 
    {
        printf("\nLibrary System Menu:\n");
        printf("1. Insert a new book\n");
	printf("2. Delete a new book\n");
	printf("3. Display all books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                printf("Enter Book Title: ");
                scanf(" %[^\n]", title);
                printf("Enter Author Name: ");
                scanf(" %[^\n]", author);
                insertBook(id, title, author);
                break;

            case 2:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;

            case 3:
                displayBooks();
                break;

            case 4:
                deallocateList();
                printf("Exiting the program\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}