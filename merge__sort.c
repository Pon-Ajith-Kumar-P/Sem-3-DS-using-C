#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2;

    // Input number of elements for array 1
    printf("\nEnter number of elements in array 1: ");
    scanf("%d", &n1);
    if (n1 <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }
    int* arr1 = (int*)malloc(n1 * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input elements for array 1
    printf("\nEnter %d elements in the array 1\n", n1);
    for (int i = 0; i < n1; i++) {
        printf("\nElement %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    // Input number of elements for array 2
    printf("\nEnter number of elements in array 2: ");
    scanf("%d", &n2);
    if (n2 <= 0) {
        printf("Invalid number of elements.\n");
        free(arr1);
        return 1;
    }
    int* arr2 = (int*)malloc(n2 * sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed.\n");
        free(arr1);
        return 1;
    }

    // Input elements for array 2
    printf("\nEnter %d elements in the array 2\n", n2);
    for (int i = 0; i < n2; i++) {
        printf("\nElement %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    // Allocate memory for the merged array
    int* arr3 = (int*)malloc((n1 + n2) * sizeof(int));
    if (arr3 == NULL) {
        printf("Memory allocation failed.\n");
        free(arr1);
        free(arr2);
        return 1;
    }

    // Merge arrays
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }

    // Display merged and sorted array
    printf("\nMerged Successfully");
    printf("\nDisplaying %d Sorted Elements\n", n1 + n2);
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d\t", arr3[i]);
    }

    // Free allocated memory
    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}