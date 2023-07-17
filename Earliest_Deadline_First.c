#include <stdio.h>
typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
    int deadline;
} Process;
void EDF_Scheduling(Process processes[], int n) {
    int current_time = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[j].deadline < processes[i].deadline)
                {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    printf("Process\tArrival Time\tBurst Time\tDeadline\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].deadline);
    }

    printf("\nExecution order: ");

    for (i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        printf("%d ", processes[i].process_id);
        current_time += processes[i].burst_time;
    }
}

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        processes[i].process_id = i + 1;
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Enter deadline: ");
        scanf("%d", &processes[i].deadline);
    }

    EDF_Scheduling(processes, n);

    return 0;
}
