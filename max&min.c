#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // For dynamic memory allocation

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Max-Heapify for max heap
void max_heapify(int a[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) 
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) 
    {
        largest = right;
    }

    if (largest != i) 
    {
        swap(&a[i], &a[largest]);
        max_heapify(a, n, largest);
    }
}

// Min-Heapify for min heap
void min_heapify(int a[], int n, int i) 
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[smallest]) 
    {
        smallest = left;
    }
    if (right < n && a[right] < a[smallest]) 
    {
        smallest = right;
    }

    if (smallest != i) 
    {
        swap(&a[i], &a[smallest]);
        min_heapify(a, n, smallest);
    }
}

// Insert into max heap
void insertMaxHeap(int a[], int *n, int value) 
{
    a[*n] = value;
    int i = *n;
    (*n)++;

    while (i != 0 && a[(i - 1) / 2] < a[i]) {
        swap(&a[i], &a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Insert into min heap
void insertMinHeap(int a[], int *n, int value) 
{
    a[*n] = value;
    int i = *n;
    (*n)++;

    while (i != 0 && a[(i - 1) / 2] > a[i]) {
        swap(&a[i], &a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Delete max from max heap
int deleteMax(int a[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int max = a[0];
    a[0] = a[*n - 1];
    (*n)--;

    max_heapify(a, *n, 0);
    return max;
}

// Delete min from min heap
int deleteMin(int a[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int min = a[0];
    a[0] = a[*n - 1];
    (*n)--;

    min_heapify(a, *n, 0);
    return min;
}

// Print heap tree view
void printHeapTreeView(int a[], int n, int isMaxHeap) {
    int height = (int)log2(n) + 1;
    int space = pow(2, height) - 1;
    int level = 1;

    printf("\nThe %s heap tree view with spaces is:\n", isMaxHeap ? "max" : "min");
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

// Print heap as array
void printHeapArray(int a[], int n, int isMaxHeap) {
    printf("\nThe %s heap as an array is: ", isMaxHeap ? "max" : "min");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int nMax = 0, nMin = 0, choice, value, count, heapType;
    int aMax[100], aMin[100];  // Arrays for max heap and min heap

    while (1) {
        printf("\nSelect Heap Type:\n1. Max Heap\n2. Min Heap\nEnter choice: ");
        scanf("%d", &heapType);
        
        if (heapType == 1 || heapType == 2) {
            while (1) {
                printf("\n1. Insert Multiple Elements\n2. Delete Max/Min\n3. Print Heap (Array View)\n4. Print Heap (Tree View)\n5. Exit");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);
                
                switch(choice) 
                {
                    case 1:
                        printf("Enter the number of elements to insert: ");
                        scanf("%d", &count);

                        printf("Enter the values to insert: ");
                        for (int i = 0; i < count; i++) {
                            scanf("%d", &value);
                            if (heapType == 1) {
                                insertMaxHeap(aMax, &nMax, value);
                            } else {
                                insertMinHeap(aMin, &nMin, value);
                            }
                        }
                        printf("Inserted %d elements into the %s heap.\n", count, (heapType == 1) ? "max" : "min");
                        break;

                    case 2:
                        if (heapType == 1) {
                            value = deleteMax(aMax, &nMax);
                        } else {
                            value = deleteMin(aMin, &nMin);
                        }
                        if (value != -1) {
                            printf("Deleted %s element %d from the heap.\n", (heapType == 1) ? "max" : "min", value);
                        }
                        break;

                    case 3:
                        if (heapType == 1) {
                            printHeapArray(aMax, nMax, 1);
                        } else {
                            printHeapArray(aMin, nMin, 0);
                        }
                        break;

                    case 4:
                        if (heapType == 1) {
                            printHeapTreeView(aMax, nMax, 1);
                        } else {
                            printHeapTreeView(aMin, nMin, 0);
                        }
                        break;

                    case 5:
                        printf("Exiting...\n");
                        return 0;

                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
        } else {
            printf("Invalid heap type selection. Exiting...\n");
            return 0;
        }
    }

    return 0;
}
