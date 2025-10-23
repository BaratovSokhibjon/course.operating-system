/*
 * Dynamic Memory Allocation
 * Demonstrates malloc, calloc, realloc, and free
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void demonstrate_malloc() {
    printf("=== malloc example ===\n");

    // Allocate memory for array of 5 integers
    int *arr = (int *)malloc(5 * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    // Initialize values
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);  // Don't forget to free!
    printf("\n");
}

void demonstrate_calloc() {
    printf("=== calloc example (initializes to 0) ===\n");

    // Allocate and initialize to zero
    int *arr = (int *)calloc(5, sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d (initialized to 0)\n", i, arr[i]);
    }

    free(arr);
    printf("\n");
}

void demonstrate_realloc() {
    printf("=== realloc example ===\n");

    int *arr = (int *)malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++) {
        arr[i] = i + 1;
    }

    printf("Original array (size 3): ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Resize to 5 elements
    arr = (int *)realloc(arr, 5 * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Reallocation failed!\n");
        return;
    }

    // Add new elements
    arr[3] = 4;
    arr[4] = 5;

    printf("Resized array (size 5): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    printf("\n");
}

int main() {
    demonstrate_malloc();
    demonstrate_calloc();
    demonstrate_realloc();

    return 0;
}
