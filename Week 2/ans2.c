#include <stdio.h>

void drawPattern() {
    for (int i = 0; i < 10; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("!        !\n");
    }
    for (int i = 0; i < 10; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    drawPattern();
    return 0;
}
