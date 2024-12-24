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
int binarySearch(ArrayADT *arr, int key);
void sortArray(ArrayADT *arr);

int main() {
    ArrayADT arr;
    initializeArray(&arr);

    int choice, element, index;

    while (1) {
        printf("\n1. Add Element\n2. Display Array\n3. Binary Search\n4. Exit\n");
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
                sortArray(&arr);
                printf("Enter element to search (Binary Search): ");
                scanf("%d", &element);
                index = binarySearch(&arr, element);
                if (index != -1) {
                    printf("Element %d found at index %d (Binary Search).\n", element, index);
                } else {
                    printf("Element %d not found (Binary Search).\n", element);
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

void sortArray(ArrayADT *arr) {
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

int binarySearch(ArrayADT *arr, int key) {
    int left = 0;
    int right = arr->size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr->data[mid] == key) {
            return mid;
        }
        if (arr->data[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
