#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

struct Process {
    int number;
    int arrival_time;
    int run_time;
};

void swap(struct Process* first, struct Process* second) {
    struct Process tmp = *second;
    *second = *first;
    *first = tmp;
}


void sort(struct Process* processes, int n) {
    for (int i = 0;i < n - 1; i++) {
        for (int j = 0;j < n - i - 1; j++) {
            if ((processes[j].arrival_time == processes[j + 1].arrival_time && processes[j].number > processes[j + 1].number) ||
                processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

int main() {
    FILE *file = fopen("ex3.in", "r");
    int n;
    fscanf(file, "n = %d\n", &n);
    int* completion_time = (int*) malloc(sizeof(int) * n);
    int* turn_around_time = (int*) malloc(sizeof(int) * n);
    int* wait_time = (int*) malloc(sizeof(int) * n);
    int* executed_time = (int*) malloc(sizeof(int) * n);
    bool* completed = (bool*) malloc(sizeof(bool) * n);
    struct Process* processes = (struct Process*) malloc(sizeof(struct Process) * n);

    for (int i = 0; i < n; i++) {
        executed_time[i] = 0;
        processes[i].number = i;
        fscanf(file, "arrival_time = %d, run_time = %d\n", &processes[i].arrival_time,  &processes[i].run_time);
    }
    printf("Please input quantum time\n");
    int quantum_time;
    scanf("%d", &quantum_time);

    sort(processes, n);

    int current_time = 0;

    int sum_wait_time = 0;
    int sum_turn_around_time = 0;

    while (true) {
        bool waiting_processes = false;
        for (int i = 0; i < n; i++) {
            int process_number = processes[i].number;
            if (completed[process_number]) {
                continue;
            }
            // wait until process start if have no other waiting processes
            if (current_time < processes[i].arrival_time) {
                if (waiting_processes == true) {
                    // all consequent processes has > current_time
                    break;
                }
                current_time = processes[i].arrival_time;
            }
            // process executed completly
            if (quantum_time + executed_time[process_number] >= processes[i].run_time) {

                current_time += processes[i].run_time - executed_time[process_number];
                wait_time[process_number] = current_time - processes[i].arrival_time - processes[i].run_time;
                completion_time[process_number] = current_time;

                turn_around_time[process_number] = completion_time[process_number] - processes[i].arrival_time;

                sum_turn_around_time += turn_around_time[process_number];
                sum_wait_time += wait_time[process_number];
                completed[process_number] = true;
            } else { // process is not finished, waiting for next execution
                waiting_processes = true;
                executed_time[process_number] += quantum_time;
                current_time += quantum_time;
            }
        }

        if (waiting_processes == false) {
            break;
        }
    }
    printf("Proc\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i, completion_time[i], turn_around_time[i], wait_time[i]);
    }
    float avg_wait_time = (float) sum_wait_time / n;
    float avg_turn_around_time = (float) sum_turn_around_time / n;
    printf("average waiting time: %.2f\naverage turn around time: %.2f\n", avg_wait_time, avg_turn_around_time);

    free(completion_time);
    free(wait_time);
    free(turn_around_time);
    free(completed);
    free(processes);
}