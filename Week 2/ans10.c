#include <stdio.h>

int main() {
    int n, smallest, position;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    smallest = arr[0];
    position = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            position = i;
        }
    }
    printf("Smallest number is %d at array position %d\n", smallest, position);
    return 0;
}
