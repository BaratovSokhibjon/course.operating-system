/*
 * Deadlock Example
 * Demonstrates how deadlock can occur with improper lock ordering
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void *thread1_func(void *arg) {
    printf("Thread 1: Attempting to acquire lock1\n");
    pthread_mutex_lock(&lock1);
    printf("Thread 1: Acquired lock1\n");

    sleep(1);  // Simulate some work

    printf("Thread 1: Attempting to acquire lock2\n");
    pthread_mutex_lock(&lock2);  // Will wait forever
    printf("Thread 1: Acquired lock2 (never happens)\n");

    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    return NULL;
}

void *thread2_func(void *arg) {
    printf("Thread 2: Attempting to acquire lock2\n");
    pthread_mutex_lock(&lock2);
    printf("Thread 2: Acquired lock2\n");

    sleep(1);  // Simulate some work

    printf("Thread 2: Attempting to acquire lock1\n");
    pthread_mutex_lock(&lock1);  // Will wait forever
    printf("Thread 2: Acquired lock1 (never happens)\n");

    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    printf("=== Deadlock Example ===\n");
    printf("This program will hang due to deadlock!\n");
    printf("Press Ctrl+C to terminate.\n\n");

    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Completed (this will never print)\n");
    return 0;
}
