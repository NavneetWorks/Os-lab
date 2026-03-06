#include<stdio.h>
#include<limits.h>

void sjf_non_preemptive(int at[],int bt[],int n){
    int wt[n],tat[n],rt[n],ct[n],done[n];
    int time=0,completed=0;

    for(int i=0;i<n;i++) done[i]=0;

    while(completed<n){
        int min=INT_MAX,idx=-1;

        for(int i=0;i<n;i++){
            if(at[i]<=time && done[i]==0 && bt[i]<min){
                min=bt[i];
                idx=i;
            }
        }

        if(idx==-1){
            time++;
            continue;
        }

        rt[idx]=time-at[idx];
        ct[idx]=time+bt[idx];
        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-bt[idx];

        time=ct[idx];
        done[idx]=1;
        completed++;
    }

    float avgwt=0,avgtat=0,avgrt=0;

    printf("\nSJF Non Preemptive\n");
    printf("P\tAT\tBT\tWT\tTAT\tRT\n");

    for(int i=0;i<n;i++){
        avgwt+=wt[i];
        avgtat+=tat[i];
        avgrt+=rt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i],rt[i]);
    }

    printf("Average WT : %.2f\n",avgwt/n);
    printf("Average TAT : %.2f\n",avgtat/n);
    printf("Average RT : %.2f\n",avgrt/n);
}

void sjf_preemptive(int at[],int bt[],int n){
    int rt[n],wt[n],tat[n],ct[n],start[n];
    int time=0,completed=0;

    for(int i=0;i<n;i++){
        rt[i]=bt[i];
        start[i]=-1;
    }

    while(completed<n){
        int min=INT_MAX,idx=-1;

        for(int i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0 && rt[i]<min){
                min=rt[i];
                idx=i;
            }
        }

        if(idx==-1){
            time++;
            continue;
        }

        if(start[idx]==-1)
            start[idx]=time;

        rt[idx]--;
        time++;

        if(rt[idx]==0){
            completed++;
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
        }
    }

    float avgwt=0,avgtat=0,avgrt=0;

    printf("\nSJF Preemptive (SRTF)\n");
    printf("P\tAT\tBT\tWT\tTAT\tRT\n");

    for(int i=0;i<n;i++){
        int response=start[i]-at[i];

        avgwt+=wt[i];
        avgtat+=tat[i];
        avgrt+=response;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i],response);
    }

    printf("Average WT : %.2f\n",avgwt/n);
    printf("Average TAT : %.2f\n",avgtat/n);
    printf("Average RT : %.2f\n",avgrt/n);
}

int main(){
    int n,choice;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n],bt[n];

    for(int i=0;i<n;i++){
        printf("Enter AT of P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Enter BT of P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    printf("\n1. Preemptive SJF\n2. Non Preemptive SJF\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    if(choice==1)
        sjf_preemptive(at,bt,n);
    else if(choice==2)
        sjf_non_preemptive(at,bt,n);
    else
        printf("Invalid choice");

    return 0;
}
