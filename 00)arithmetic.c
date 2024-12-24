#include<stdio.h>

struct Complex {
    float real;
    float imag;
};

struct Complex AddComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

struct Complex SubtractComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

struct Complex MultiplyComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    result.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return result;
}

int main() {
    struct Complex num1, num2, result;

    // Input first complex number
    printf("Enter the first complex number:\n");
    printf("Real part: ");
    scanf("%f", &num1.real);
    printf("Imaginary part: ");
    scanf("%f", &num1.imag);

    // Input second complex number
    printf("Enter the second complex number:\n");
    printf("Real part: ");
    scanf("%f", &num2.real);
    printf("Imaginary part: ");
    scanf("%f", &num2.imag);

    // Add complex numbers
    result = AddComplex(num1, num2);
    printf("Sum: %.1f + %.1fi\n", result.real, result.imag);

    // Subtract complex numbers
    result = SubtractComplex(num1, num2);
    printf("Difference: %.1f + %.1fi\n", result.real, result.imag);

    // Multiply complex numbers
    result = MultiplyComplex(num1, num2);
    printf("Product: %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}
