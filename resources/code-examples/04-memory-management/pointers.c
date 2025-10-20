/*
 * Pointer Basics
 * Understanding pointers and memory addresses
 */

#include <stdio.h>

void swap_wrong(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("  Inside swap_wrong: a=%d, b=%d\n", a, b);
}

void swap_correct(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("  Inside swap_correct: *a=%d, *b=%d\n", *a, *b);
}

int main() {
    int x = 10;
    int *ptr = &x;

    printf("=== Pointer Basics ===\n");
    printf("x = %d\n", x);
    printf("Address of x = %p\n", (void *)&x);
    printf("ptr = %p (points to x)\n", (void *)ptr);
    printf("*ptr = %d (value at address)\n\n", *ptr);

    // Modify through pointer
    *ptr = 20;
    printf("After *ptr = 20:\n");
    printf("x = %d\n\n", x);

    // Pointer arithmetic
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf("=== Pointer Arithmetic ===\n");
    for (int i = 0; i < 5; i++) {
        printf("*(p + %d) = %d, Address: %p\n", i, *(p + i), (void *)(p + i));
    }
    printf("\n");

    // Pass by value vs pass by reference
    printf("=== Pass by Value vs Reference ===\n");
    int a = 5, b = 10;

    printf("Before swap_wrong: a=%d, b=%d\n", a, b);
    swap_wrong(a, b);
    printf("After swap_wrong: a=%d, b=%d (unchanged!)\n\n", a, b);

    printf("Before swap_correct: a=%d, b=%d\n", a, b);
    swap_correct(&a, &b);
    printf("After swap_correct: a=%d, b=%d (swapped!)\n", a, b);

    return 0;
}
