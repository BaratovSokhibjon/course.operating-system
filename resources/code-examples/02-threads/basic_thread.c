/*
 * Basic Thread Creation
 * Demonstrates creating and joining threads using pthreads
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg) {
    int thread_num = *(int *)arg;
    printf("Thread %d: Starting (Thread ID: %lu)\n", thread_num, pthread_self());
    sleep(2);
    printf("Thread %d: Finishing\n", thread_num);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_args[3];

    printf("Main: Creating threads\n");

    for (int i = 0; i < 3; i++) {
        thread_args[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    printf("Main: All threads created, waiting for completion\n");

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
        printf("Main: Thread %d joined\n", i + 1);
    }

    printf("Main: All threads completed\n");
    return 0;
}
