#include<stdio.h>

void round_robin(int n,int at[],int bt[],int tq)
{
    int rem[n],ct[n],tat[n],wt[n],rt[n];
    int started[n],in_queue[n],queue[1000];
    int front=0,rear=0,time=0,completed=0;

    for(int i=0;i<n;i++)
    {
        rem[i]=bt[i];
        started[i]=0;
        in_queue[i]=0;
    }

    while(completed<n)
    {
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && rem[i]>0 && in_queue[i]==0)
            {
                queue[rear]=i;
                rear++;
                in_queue[i]=1;
            }
        }

        if(front==rear)
        {
            time++;
            continue;
        }

        int idx=queue[front];
        front++;
        in_queue[idx]=0;

        if(started[idx]==0)
        {
            rt[idx]=time-at[idx];
            started[idx]=1;
        }

        int run;

        if(rem[idx]>tq)
            run=tq;
        else
            run=rem[idx];

        for(int i=0;i<run;i++)
        {
            time++;
            rem[idx]--;

            for(int j=0;j<n;j++)
            {
                if(j!=idx && at[j]<=time && rem[j]>0 && in_queue[j]==0)
                {
                    queue[rear]=j;
                    rear++;
                    in_queue[j]=1;
                }
            }
        }

        if(rem[idx]==0)
        {
            completed++;
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
        }
        else
        {
            queue[rear]=idx;
            rear++;
            in_queue[idx]=1;
        }
    }

    float avgwt=0,avgtat=0,avgrt=0;

    printf("\nRound Robin Scheduling\n");
    printf("P\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
        avgwt+=wt[i];
        avgtat+=tat[i];
        avgrt+=rt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }

    printf("Average WT : %.2f\n",avgwt/n);
    printf("Average TAT : %.2f\n",avgtat/n);
    printf("Average RT : %.2f\n",avgrt/n);
}

int main()
{
    int n,tq;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n],bt[n];

    for(int i=0;i<n;i++)
    {
        printf("\nProcess P%d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    if(tq<=0)
    {
        printf("Invalid Time Quantum\n");
        return 0;
    }

    round_robin(n,at,bt,tq);

    return 0;
}
