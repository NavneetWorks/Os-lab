#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

typedef struct {
    int id;
    int burst;
    int deadline;
    int period;
    int remaining;
    int weight;
} Process;

void sortEDF(Process p[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(p[i].deadline > p[j].deadline) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void sortRMS(Process p[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(p[i].period > p[j].period) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void EDF(Process p[], int n) {
    float utilization = 0;

    for(int i=0;i<n;i++)
        utilization += (float)p[i].burst / p[i].deadline;

    sortEDF(p, n);

    printf("\n===== Earliest Deadline First (EDF) =====\n");
    printf("CPU Utilization: %.2f\n", utilization);
    printf("Schedulable: %s\n", (utilization <= 1.0) ? "YES" : "NO");

    int time = 0;
    printf("ID\tBT\tDL\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++) {
        int ct = time + p[i].burst;
        int tat = ct;
        int wt = tat - p[i].burst;

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].burst, p[i].deadline, ct, wt, tat);

        time = ct;
    }
}

void RMS(Process p[], int n) {
    float utilization = 0;

    for(int i=0;i<n;i++)
        utilization += (float)p[i].burst / p[i].period;

    float bound = n * (pow(2, 1.0/n) - 1);

    sortRMS(p, n);

    printf("\n===== Rate Monotonic Scheduling (RMS) =====\n");
    printf("CPU Utilization: %.2f\n", utilization);
    printf("RM Bound: %.4f\n", bound);
    printf("Schedulable: %s\n", (utilization <= bound) ? "YES" : "NO");

    int time = 0;
    printf("ID\tBT\tPR\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++) {
        int ct = time + p[i].burst;
        int tat = ct;
        int wt = tat - p[i].burst;

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].burst, p[i].period, ct, wt, tat);

        time = ct;
    }
}

void Proportional(Process p[], int n) {
    int total_weight = 0;

    for(int i=0;i<n;i++)
        total_weight += p[i].weight;

    printf("\n===== Proportional Scheduling =====\n");
    printf("ID\tWeight\tCPU Share(%%)\n");

    for(int i=0;i<n;i++) {
        float share = ((float)p[i].weight / total_weight) * 100;
        printf("%d\t%d\t%.2f%%\n", p[i].id, p[i].weight, share);
    }
}

int main() {
    int n;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        p[i].id = i;

        printf("\nProcess %d\n", i);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Deadline: ");
        scanf("%d", &p[i].deadline);

        printf("Period: ");
        scanf("%d", &p[i].period);

        printf("Weight (for proportional scheduling): ");
        scanf("%d", &p[i].weight);
    }

    EDF(p, n);
    RMS(p, n);
    Proportional(p, n);

    return 0;
}