#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

typedef struct {
    char *title;
    char *author;
    int publicationYear;
    float price;
} Book;

void addBook(Book *books, int *count);
void displayBooks(Book *books, int count);
Book* searchBook(Book *books, int count, char *title);
void updatePrice(Book *book, float newPrice);
void deleteBook(Book *books, int *count, char *title);

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;
    char title[TITLE_LENGTH];
    float newPrice;

    while (1) {
        printf("\nLibrary Database Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Update Book Price\n");
        printf("5. Delete Book\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                printf("Enter the title of the book to search: ");
                scanf("%[^\n]", title);
                getchar();
                {
                    Book *book = searchBook(books, count, title);
                    if (book) {
                        printf("Book found:\nTitle: %s\nAuthor: %s\nYear: %d\nPrice: %.2f\n", book->title, book->author, book->publicationYear, book->price);
                    } else {
                        printf("Book not found.\n");
                    }
                }
                break;
            case 4:
                printf("Enter the title of the book to update the price: ");
                scanf("%[^\n]", title);
                getchar();
                {
                    Book *book = searchBook(books, count, title);
                    if (book) {
                        printf("Enter new price: ");
                        scanf("%f", &newPrice);
                        updatePrice(book, newPrice);
                        printf("Price updated successfully.\n");
                    } else {
                        printf("Book not found.\n");
                    }
                }
                break;
            case 5:
                printf("Enter the title of the book to delete: ");
                scanf("%[^\n]", title);
                getchar();
                deleteBook(books, &count, title);
                break;
            case 6:
                for (int i = 0; i < count; i++) {
                    free(books[i].title);
                    free(books[i].author);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addBook(Book *books, int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Database is full. Cannot add more books.\n");
        return;
    }

    books[*count].title = (char *)malloc(TITLE_LENGTH * sizeof(char));
    books[*count].author = (char *)malloc(AUTHOR_LENGTH * sizeof(char));

    printf("Enter title: ");
    scanf("%[^\n]", books[*count].title);
    getchar();

    printf("Enter author: ");
    scanf("%[^\n]", books[*count].author);
    getchar();

    printf("Enter publication year: ");
    scanf("%d", &books[*count].publicationYear);
    
    printf("Enter price: ");
    scanf("%f", &books[*count].price);
    getchar();

    (*count)++;
}

void displayBooks(Book *books, int count) {
    if (count == 0) {
        printf("No books in the database.\n");
        return;
    }

    printf("\nBooks in Database:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s\nAuthor: %s\nYear: %d\nPrice: %.2f\n", books[i].title, books[i].author, books[i].publicationYear, books[i].price);
    }
}

Book* searchBook(Book *books, int count, char *title) {
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return &books[i];
        }
    }
    return NULL;
}

void updatePrice(Book *book, float newPrice) {
    book->price = newPrice;
}

void deleteBook(Book *books, int *count, char *title) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            free(books[i].title);
            free(books[i].author);
            for (int j = i; j < *count - 1; j++) {
                books[j] = books[j + 1];
            }
            (*count)--;
            printf("Book deleted successfully.\n");
            return;
        }
    }
    printf("Book not found.\n");
}
