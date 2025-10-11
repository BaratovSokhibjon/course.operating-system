/*
 * Reader-Writer Problem
 * Multiple readers can read simultaneously, but writers need exclusive access
 */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int shared_data = 0;
int reader_count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t write_lock = PTHREAD_MUTEX_INITIALIZER;

void *reader(void *arg) {
    int id = *(int *)arg;

    for (int i = 0; i < 3; i++) {
        // Entry section
        pthread_mutex_lock(&mutex);
        reader_count++;
        if (reader_count == 1) {
            pthread_mutex_lock(&write_lock);  // First reader locks writers
        }
        pthread_mutex_unlock(&mutex);

        // Critical section - reading
        printf("Reader %d: Reading data = %d\n", id, shared_data);
        sleep(1);

        // Exit section
        pthread_mutex_lock(&mutex);
        reader_count--;
        if (reader_count == 0) {
            pthread_mutex_unlock(&write_lock);  // Last reader unlocks writers
        }
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    return NULL;
}

void *writer(void *arg) {
    int id = *(int *)arg;

    for (int i = 0; i < 2; i++) {
        pthread_mutex_lock(&write_lock);

        // Critical section - writing
        shared_data++;
        printf("Writer %d: Writing data = %d\n", id, shared_data);
        sleep(2);

        pthread_mutex_unlock(&write_lock);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t readers[3], writers[2];
    int reader_ids[3] = {1, 2, 3};
    int writer_ids[2] = {1, 2};

    printf("=== Reader-Writer Problem ===\n\n");

    for (int i = 0; i < 2; i++) {
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(readers[i], NULL);
    }

    printf("\nAll readers and writers completed!\n");

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&write_lock);

    return 0;
}
