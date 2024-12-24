#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} ArrayADT;

void initializeArray(ArrayADT *arr);
void addElement(ArrayADT *arr, int element);
void displayArray(const ArrayADT *arr);
int linearSearch(const ArrayADT *arr, int key);

int main() {
    ArrayADT arr;
    initializeArray(&arr);

    int choice, element, index;

    while (1) {
        printf("\n1. Add Element\n2. Display Array\n3. Linear Search\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &element);
                addElement(&arr, element);
                break;
            case 2:
                displayArray(&arr);
                break;
            case 3:
                printf("Enter element to search (Linear Search): ");
                scanf("%d", &element);
                index = linearSearch(&arr, element);
                if (index != -1) {
                    printf("Element %d found at index %d (Linear Search).\n", element, index);
                } else {
                    printf("Element %d not found (Linear Search).\n", element);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

void initializeArray(ArrayADT *arr) {
    arr->size = 0;
}

void addElement(ArrayADT *arr, int element) {
    if (arr->size < MAX_SIZE) {
        arr->data[arr->size] = element;
        arr->size++;
    } else {
        printf("Array is full. Cannot add more elements.\n");
    }
}

void displayArray(const ArrayADT *arr) {
    if (arr->size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int linearSearch(const ArrayADT *arr, int key) {
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == key) {
            return i;
        }
    }
    return -1;
}
