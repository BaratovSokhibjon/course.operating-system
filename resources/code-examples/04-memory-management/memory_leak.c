/*
 * Memory Leak Example
 * Demonstrates common memory leak scenarios
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Memory leak: forgetting to free
void leak_example1() {
    printf("Leak 1: Forgetting to free\n");
    int *data = (int *)malloc(100 * sizeof(int));
    // ... use data ...
    // Missing free(data)!
}

// Memory leak: losing pointer reference
void leak_example2() {
    printf("Leak 2: Losing pointer reference\n");
    char *str = (char *)malloc(50);
    strcpy(str, "Hello");

    str = (char *)malloc(50);  // Old memory lost!
    strcpy(str, "World");

    free(str);  // Only frees second allocation
}

// Correct: no leak
void no_leak_example() {
    printf("No leak: Proper memory management\n");
    int *data = (int *)malloc(100 * sizeof(int));

    if (data != NULL) {
        // Use data
        for (int i = 0; i < 100; i++) {
            data[i] = i;
        }
        free(data);  // Properly freed!
    }
}

// Double free error
void double_free_example() {
    printf("Double free (undefined behavior):\n");
    int *data = (int *)malloc(10 * sizeof(int));
    free(data);
    // free(data);  // DANGER: Double free! (commented to avoid crash)
    printf("(Avoided double free by commenting it out)\n");
}

int main() {
    printf("=== Memory Leak Examples ===\n\n");

    leak_example1();
    leak_example2();
    no_leak_example();
    double_free_example();

    printf("\nNote: Use valgrind to detect memory leaks:\n");
    printf("  valgrind --leak-check=full ./memory_leak\n");

    return 0;
}
