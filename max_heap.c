#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to swap the values of two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify up after insertion
void heapifyUp(int a[], int index) {
    while (index > 0 && a[(index - 1) / 2] < a[index]) {
        swap(&a[(index - 1) / 2], &a[index]);
        index = (index - 1) / 2;
    }
}

// Function to insert a new value into the heap
void insertNode(int a[], int* n, int value) {
    a[*n] = value;
    heapifyUp(a, *n);
    (*n)++;
}

// Function to heapify down after deletion
void heapifyDown(int a[], int n, int index) {
    while (2 * index + 1 < n) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (a[left] > a[largest]) {
            largest = left;
        }
        if (right < n && a[right] > a[largest]) {
            largest = right;
        }
        if (largest == index) {
            break;
        }

        swap(&a[index], &a[largest]);
        index = largest;
    }
}

// Function to delete the max value (root) from the heap
int deleteMax(int a[], int* n) {
    if (*n == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int maxValue = a[0];
    a[0] = a[*n - 1];
    (*n)--;
    heapifyDown(a, *n, 0);
    return maxValue;
}

// Function to print the heap as an array (level order traversal)
void printHeapArray(int a[], int n) {
    if (n == 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("The max heap as an array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void printHeapTreeView(int a[], int n) {
    int height = (int)log2(n) + 1;

    printf("\nThe max heap tree view with spaces is:\n");
    for (int level = 0; level < height; level++) {
        int levelStart = pow(2, level) - 1;
        int levelEnd = pow(2, level + 1) - 1;
        int space = pow(2, height - level) - 1;

        // Print leading spaces
        for (int i = 0; i < space / 2; i++) {
            printf(" ");
        }

        for (int i = levelStart; i < levelEnd && i < n; i++) {
            printf("%d", a[i]);

            // Print spaces between nodes
            for (int j = 0; j < space; j++) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int a[100];
    int n = 0;  // Size of the heap
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete Max\n3. Print Max Heap (Array View)\n4. Print Max Heap (Tree View)\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertNode(a, &n, value);
                break;
            case 2:
                value = deleteMax(a, &n);
                if (value != -1) {
                    printf("Deleted max value: %d\n", value);
                }
                break;
            case 3:
                printHeapArray(a, n);
                break;
            case 4:
                printHeapTreeView(a, n);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
