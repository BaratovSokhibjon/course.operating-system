/*
 * Thread Race Condition Example
 * Demonstrates problems when threads access shared data without synchronization
 */

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define ITERATIONS 100000

int counter = 0;  // Shared variable

void *increment_counter(void *arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        counter++;  // Not atomic! Race condition here
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    printf("Starting with counter = %d\n", counter);
    printf("Expected final value: %d\n", NUM_THREADS * ITERATIONS);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    // Wait for all threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Actual final value: %d\n", counter);
    printf("Difference: %d (due to race condition)\n",
           (NUM_THREADS * ITERATIONS) - counter);

    return 0;
}
