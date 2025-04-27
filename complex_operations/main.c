#include <stdio.h>
#include <stdlib.h>

struct Complex
{
    int real;
    int imag;
};

struct Complex add(struct Complex, struct Complex);
struct Complex sub(struct Complex, struct Complex);
struct Complex mult(struct Complex, struct Complex);
struct Complex get_complex();

int main()
{
    struct Complex complex1, complex2, sum, diff, product;

    complex1 = get_complex();
    complex2 = get_complex();

    // Print complex numbers
    printf("Complex number 1: %d + %di\n", complex1.real, complex1.imag);
    printf("Complex number 2: %d + %di\n", complex2.real, complex2.imag);

    sum = add(complex1, complex2);
    diff = sub(complex1, complex2);
    product = mult(complex1, complex2);

    // Print results of operations
    printf("Sum: %d + %di\n", sum.real, sum.imag);
    printf("Difference: %d + %di\n", diff.real, diff.imag);
    printf("Product: %d + %di\n", product.real, product.imag);

    return 0;
}

struct Complex get_complex()
{
    struct Complex temp;
    printf("Enter real part: ");
    scanf("%d", &temp.real);
    printf("Enter imaginary part: ");
    scanf("%d", &temp.imag);
    return temp;
}

struct Complex add(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

struct Complex sub(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

struct Complex mult(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}
