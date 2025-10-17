/*
 * CPU Scheduling Algorithms Simulation
 * Implements FCFS, SJF, Round Robin, and Priority scheduling
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

void print_results(Process processes[], int n, const char *algorithm) {
    float avg_waiting = 0, avg_turnaround = 0;

    printf("\n=== %s Scheduling ===\n", algorithm);
    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);

        avg_waiting += processes[i].waiting_time;
        avg_turnaround += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting / n);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround / n);
}

// First Come First Serve
void fcfs(Process processes[], int n) {
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;

        current_time = processes[i].completion_time;
    }

    print_results(processes, n, "FCFS (First Come First Serve)");
}

// Shortest Job First (Non-preemptive)
void sjf(Process processes[], int n) {
    int completed = 0, current_time = 0;
    int is_completed[MAX_PROCESSES] = {0};

    while (completed < n) {
        int shortest = -1;
        int min_burst = 99999;

        for (int i = 0; i < n; i++) {
            if (!is_completed[i] &&
                processes[i].arrival_time <= current_time &&
                processes[i].burst_time < min_burst) {
                shortest = i;
                min_burst = processes[i].burst_time;
            }
        }

        if (shortest == -1) {
            current_time++;
            continue;
        }

        processes[shortest].waiting_time = current_time - processes[shortest].arrival_time;
        processes[shortest].completion_time = current_time + processes[shortest].burst_time;
        processes[shortest].turnaround_time = processes[shortest].completion_time -
                                              processes[shortest].arrival_time;

        current_time = processes[shortest].completion_time;
        is_completed[shortest] = 1;
        completed++;
    }

    print_results(processes, n, "SJF (Shortest Job First)");
}

// Round Robin
void round_robin(Process processes[], int n, int quantum) {
    int current_time = 0;
    int completed = 0;

    // Copy burst times to remaining times
    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }

    while (completed < n) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 &&
                processes[i].arrival_time <= current_time) {
                done = 0;

                if (processes[i].remaining_time > quantum) {
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].waiting_time = current_time -
                                               processes[i].arrival_time -
                                               processes[i].burst_time;
                    processes[i].turnaround_time = current_time -
                                                  processes[i].arrival_time;
                    processes[i].remaining_time = 0;
                    completed++;
                }
            }
        }

        if (done) current_time++;
    }

    printf("\n=== Round Robin (Quantum = %d) ===\n", quantum);
    print_results(processes, n, "Round Robin");
}

int main() {
    // Sample processes
    Process processes[] = {
        {1, 0, 8, 3, 0, 0, 0, 0},
        {2, 1, 4, 1, 0, 0, 0, 0},
        {3, 2, 9, 2, 0, 0, 0, 0},
        {4, 3, 5, 4, 0, 0, 0, 0}
    };
    int n = 4;

    printf("=== CPU Scheduling Algorithms Simulation ===\n");
    printf("\nInput Processes:\n");
    printf("PID\tArrival\tBurst\tPriority\n");
    printf("--------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].priority);
    }

    // FCFS
    Process fcfs_processes[MAX_PROCESSES];
    memcpy(fcfs_processes, processes, sizeof(processes));
    fcfs(fcfs_processes, n);

    // SJF
    Process sjf_processes[MAX_PROCESSES];
    memcpy(sjf_processes, processes, sizeof(processes));
    sjf(sjf_processes, n);

    // Round Robin
    Process rr_processes[MAX_PROCESSES];
    memcpy(rr_processes, processes, sizeof(processes));
    round_robin(rr_processes, n, 4);

    return 0;
}
