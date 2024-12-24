#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void countingSort(int arr[], int n);
void countingSortForRadix(int arr[], int n, int exp);
void radixSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    int choice, n;
    int *arr;

    while (1) {
        printf("\nSorting Algorithms Menu\n");
        printf("1. Selection Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Counting Sort\n");
        printf("4. Radix Sort\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        printf("Enter the number of elements: ");
        scanf("%d", &n);
        arr = (int *)malloc(n * sizeof(int));

        printf("Enter the elements:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        switch (choice) {
            case 1:
                selectionSort(arr, n);
                printf("Sorted array using Selection Sort:\n");
                printArray(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                printf("Sorted array using Insertion Sort:\n");
                printArray(arr, n);
                break;
            case 3:
                countingSort(arr, n);
                printf("Sorted array using Counting Sort:\n");
                printArray(arr, n);
                break;
            case 4:
                radixSort(arr, n);
                printf("Sorted array using Radix Sort:\n");
                printArray(arr, n);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        free(arr);
    }

    return 0;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
        printf("Intermediate steps after selecting index %d:\n", i);
        printArray(arr, n);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("Intermediate steps after inserting element at index %d:\n", i);
        printArray(arr, n);
    }
}

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int *count = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
    free(count);
}

void countingSortForRadix(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    free(output);
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortForRadix(arr, n, exp);
        printf("Intermediate steps after sorting by digit with exp %d:\n", exp);
        printArray(arr, n);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
