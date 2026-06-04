#include <stdio.h>
#include <stdbool.h>

#define MAX 10

void deadlock_detection(int n, int m, int Allocation[MAX][MAX], int Request[MAX][MAX], int Available[MAX]) {
    int Work[MAX];
    bool Finish[MAX];

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
                    if (Request[i][j] > Work[j]) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    for (int j = 0; j < m; j++) {
                        Work[j] += Allocation[i][j];
                    }

                    Finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found)
            break;
    }

    bool deadlock = false;

    printf("\nDeadlocked Processes:\n");

    for (int i = 0; i < n; i++) {
        if (!Finish[i]) {
            printf("P%d\n", i);
            deadlock = true;
        }
    }

    if (!deadlock)
        printf("No Deadlock Detected\n");
}

int main() {
    int n, m;
    int Allocation[MAX][MAX], Request[MAX][MAX];
    int Available[MAX];

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    printf("Enter Number of Resource Types: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &Request[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &Available[j]);
    }

    deadlock_detection(n, m, Allocation, Request, Available);

    return 0;
}
