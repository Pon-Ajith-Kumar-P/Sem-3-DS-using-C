#include <stdio.h>

void concatenate(char *str1, char *str2) {
    while (*str1) {
        str1++;
    }
    while (*str2) {
        *str1++ = *str2++;
    }
    *str1 = '\0';
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    concatenate(str1, str2);
    printf("Concatenated string: %s\n", str1);
    return 0;
}
