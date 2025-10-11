/*
 * Producer-Consumer Problem with Semaphores
 * Classic synchronization problem using semaphores
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty;  // Counts empty slots
sem_t full;   // Counts full slots
pthread_mutex_t mutex;

void *producer(void *arg) {
    for (int i = 1; i <= NUM_ITEMS; i++) {
        sem_wait(&empty);  // Wait for empty slot
        pthread_mutex_lock(&mutex);

        // Critical section
        buffer[in] = i;
        printf("Producer: Produced item %d at position %d\n", i, in);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);  // Signal that buffer has data

        sleep(1);
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 1; i <= NUM_ITEMS; i++) {
        sem_wait(&full);  // Wait for full slot
        pthread_mutex_lock(&mutex);

        // Critical section
        int item = buffer[out];
        printf("Consumer: Consumed item %d from position %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);  // Signal that buffer has empty slot

        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    printf("Starting Producer-Consumer with buffer size %d\n\n", BUFFER_SIZE);

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    printf("\nProduction and consumption completed!\n");

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
