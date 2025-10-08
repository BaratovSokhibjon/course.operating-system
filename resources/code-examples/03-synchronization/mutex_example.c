/*
 * Mutex Example - Solving Race Condition
 * Demonstrates using mutex to protect shared data
 */

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define ITERATIONS 100000

int counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment_counter_safe(void *arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&mutex);
        counter++;  // Protected by mutex
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    printf("Starting with counter = %d\n", counter);
    printf("Expected final value: %d\n", NUM_THREADS * ITERATIONS);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter_safe, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Actual final value: %d\n", counter);
    printf("Mutex prevented race condition!\n");

    pthread_mutex_destroy(&mutex);
    return 0;
}
