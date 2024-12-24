#include <stdio.h>

float average(int n) {
    return (n * (n + 1)) / 2.0 / n;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Average of numbers from 1 to %d is %.2f\n", n, average(n));
    return 0;
}
