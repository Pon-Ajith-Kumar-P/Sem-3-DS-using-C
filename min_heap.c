#include <stdio.h>
#include <math.h>

// Swap two elements in the array
void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// Function to maintain the min-heap property by heapifying down from the given index
void min_heapify(int a[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[smallest]) {
        smallest = left;
    }
    if (right < n && a[right] < a[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(a, i, smallest);
        min_heapify(a, n, smallest);
    }
}

// Insert a new value into the min heap
int insert(int a[], int n, int value) {
    a[n] = value;  // Add the new element at the end
    int i = n;
    n++;  // Increment the size to include the new element

    // Heapify up to maintain the min-heap property
    while (i != 0 && a[(i - 1) / 2] > a[i]) {
        swap(a, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }

    return n;  // Return the updated size
}

// Remove and return the minimum element from the min heap
int deleteMin(int a[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int min = a[0];
    a[0] = a[*n - 1];
    (*n)--;

    // Heapify down to maintain the min-heap property
    min_heapify(a, *n, 0);

    return min;
}

// Function to print the min heap as a tree view with spaces
void printHeapTreeView(int a[], int n) {
    int height = (int)log2(n) + 1;
    int space = pow(2, height) - 1;
    int level = 1;

    printf("\nThe min heap tree view with spaces is:\n");
    for (int i = 0; i < n; i++) {
        if (i == pow(2, level) - 1) {
            printf("\n");
            space /= 2;
            level++;
        }
        for (int j = 0; j < space; j++) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

// Function to print the min heap in array form
void printHeapArray(int a[], int n) {
    printf("\nThe min heap as an array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n = 0, choice, value;
    int a[100]; // Assuming a maximum of 100 elements for simplicity

    while (1) {
        printf("\n1. Insert\n2. Delete Min\n3. Print Min Heap (Array View)\n4. Print Min Heap (Tree View)\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                n = insert(a, n, value);  // Update n with the new size
                printf("Inserted %d into the min heap.\n", value);
                break;

            case 2:
                value = deleteMin(a, &n);  // n will still need to be updated in deleteMin
                if (value != -1) {
                    printf("Deleted min element %d from the min heap.\n", value);
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
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
