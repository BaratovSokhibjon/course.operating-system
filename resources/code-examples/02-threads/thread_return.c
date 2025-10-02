/*
 * Thread with Return Value
 * Demonstrates how to return values from threads
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int start;
    int end;
} range_t;

void *sum_range(void *arg) {
    range_t *range = (range_t *)arg;
    int *result = malloc(sizeof(int));
    *result = 0;

    for (int i = range->start; i <= range->end; i++) {
        *result += i;
    }

    printf("Thread calculating sum from %d to %d: %d\n",
           range->start, range->end, *result);

    return result;
}

int main() {
    pthread_t thread1, thread2;
    range_t range1 = {1, 50};
    range_t range2 = {51, 100};
    int *result1, *result2;

    pthread_create(&thread1, NULL, sum_range, &range1);
    pthread_create(&thread2, NULL, sum_range, &range2);

    pthread_join(thread1, (void **)&result1);
    pthread_join(thread2, (void **)&result2);

    printf("\nTotal sum (1-100): %d\n", *result1 + *result2);
    printf("Expected: 5050\n");

    free(result1);
    free(result2);

    return 0;
}
