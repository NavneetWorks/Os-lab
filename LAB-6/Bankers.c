#include <stdio.h>
#include <stdbool.h>

#define MAX 10

void bankers_algorithm(int n, int m, int Allocation[MAX][MAX], int Max[MAX][MAX], int Available[MAX]) {
    int Need[MAX][MAX], Work[MAX];
    bool Finish[MAX];
    int SafeSequence[MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    for (int j = 0; j < m; j++)
        Work[j] = Available[j];

    for (int i = 0; i < n; i++)
        Finish[i] = false;

    int count = 0;

    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!Finish[i]) {
                bool possible = true;

                for (int j = 0; j < m; j++) {
                    if (Need[i][j] > Work[j]) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    for (int j = 0; j < m; j++) {
                        Work[j] += Allocation[i][j];
                    }

                    SafeSequence[count++] = i;
                    Finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found)
            break;
    }

    if (count == n) {
        printf("\nSystem is in a safe state.\n");
        printf("Safe sequence is: ");

        for (int i = 0; i < n; i++) {
            printf("P%d", SafeSequence[i]);
            if (i != n - 1)
                printf(" -> ");
        }
        printf("\n");
    } else {
        printf("\nSystem is not in a safe state.\n");
    }
}

int main() {
    int n, m;
    int Allocation[MAX][MAX], Max[MAX][MAX];
    int Available[MAX];

    // Input
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("Enter Maximum Demand Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &Max[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &Available[j]);
    }

    bankers_algorithm(n, m, Allocation, Max, Available);

    return 0;
}
