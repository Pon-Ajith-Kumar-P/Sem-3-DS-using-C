#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("Sum: %d\n", add(a, b));
    return 0;
}
