#include <stdio.h>
#include <math.h>

// Function to swap two elements in the array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the max-heap property
void max_heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&a[i], &a[largest]);
        max_heapify(a, n, largest);
    }
}

// Function to build a max-heap from the array
void build_max_heap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(a, n, i);
    }
}

// Heap sort function
void heap_sort(int a[], int n) {
    build_max_heap(a, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        max_heapify(a, i, 0);
    }
}

// Function to print the array
void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function to print the array as a tree view
void print_tree_view(int a[], int n) {
    int height = (int)log2(n) + 1;
    int space = pow(2, height) - 1;
    int level = 1;

    printf("\nSorted array tree view (min-heap format):\n");
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

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Original array: ");
    print_array(a, n);

    // Perform heap sort
    heap_sort(a, n);

    printf("Sorted array: ");
    print_array(a, n);

    // Print sorted array as tree view
    print_tree_view(a, n);

    return 0;
}
