#include <stdio.h>

#define MAX 10

void deadlock_detection(int n, int m, int Allocation[MAX][MAX], int Request[MAX][MAX], int Available[MAX]) {

    int Work[MAX];
    int Finish[MAX];
    int i, j, k;

    for(i = 0; i < m; i++)
        Work[i] = Available[i];

    for(i = 0; i < n; i++) {

        int allZero = 1;

        for(j = 0; j < m; j++) {

            if(Allocation[i][j] != 0) {
                allZero = 0;
                break;
            }
        }

        if(allZero)
            Finish[i] = 1;
        else
            Finish[i] = 0;
    }

    int found;

    do {

        found = 0;

        for(i = 0; i < n; i++) {

            if(Finish[i] == 0) {

                for(j = 0; j < m; j++) {

                    if(Request[i][j] > Work[j])
                        break;
                }

                if(j == m) {

                    for(k = 0; k < m; k++)
                        Work[k] += Allocation[i][k];

                    Finish[i] = 1;
                    found = 1;
                }
            }
        }

    } while(found);

    int deadlock = 0;

    printf("\nDeadlocked Processes:\n");

    for(i = 0; i < n; i++) {

        if(Finish[i] == 0) {

            printf("P%d\n", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
        printf("No Deadlock Detected\n");
}

int main() {

    int n, m;

    int Allocation[MAX][MAX];
    int Request[MAX][MAX];
    int Available[MAX];

    int i, j;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    printf("Enter Number of Resource Types: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &Request[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");

    for(i = 0; i < m; i++) {
        scanf("%d", &Available[i]);
    }

    deadlock_detection(n, m, Allocation, Request, Available);

    return 0;
}
