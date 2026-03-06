#include<stdio.h>

void fcfs(int at[], int bt[], int n){
    int wt[n], tat[n], rt[n], p[n];
    float avg_wt = 0, avg_tat = 0, avg_rt = 0;

    for(int i = 0; i < n; i++){
        p[i] = i + 1;
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(at[j] > at[j+1]){
                int temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    rt[0] = wt[0];

    avg_wt += wt[0];
    avg_tat += tat[0];
    avg_rt += rt[0];

    for(int i = 1; i < n; i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
        rt[i] = wt[i];

        avg_wt += wt[i];
        avg_tat += tat[i];
        avg_rt += rt[i];
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;
    avg_rt = avg_rt / n;

    printf("Process\tAT\tBT\tWT\tTAT\tRT\n");
    for(int i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], wt[i], tat[i], rt[i]);
    }

    printf("Average WT : %.2f\n", avg_wt);
    printf("Average TAT : %.2f\n", avg_tat);
    printf("Average RT : %.2f\n", avg_rt);
}

int main(){
    int n;

    printf("Enter the number of process : ");
    scanf("%d", &n);

    int at[n], bt[n];

    for(int i = 0; i < n; i++){
        printf("Enter arrival time of process %d : ", i+1);
        scanf("%d", &at[i]);

        printf("Enter burst time of process %d : ", i+1);
        scanf("%d", &bt[i]);
    }

    fcfs(at, bt, n);

    return 0;
}
