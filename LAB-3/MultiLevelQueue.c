#include<stdio.h>

void multilevel_queue(int n,int at[],int bt[],int q[],int tq)
{
    int rem[n],ct[n],tat[n],wt[n],rt[n];
    int started[n],in_queue[n],rr[1000];
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
            if(q[i]==1 && at[i]<=time && rem[i]>0 && in_queue[i]==0)
            {
                rr[rear]=i;
                rear++;
                in_queue[i]=1;
            }
        }

        if(front<rear)
        {
            int idx=rr[front];
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
                    if(j!=idx && q[j]==1 && at[j]<=time && rem[j]>0 && in_queue[j]==0)
                    {
                        rr[rear]=j;
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
                rr[rear]=idx;
                rear++;
                in_queue[idx]=1;
            }
        }
        else
        {
            int idx=-1;

            for(int i=0;i<n;i++)
            {
                if(q[i]==2 && at[i]<=time && rem[i]>0)
                {
                    if(idx==-1 || at[i]<at[idx] || (at[i]==at[idx] && i<idx))
                        idx=i;
                }
            }

            if(idx==-1)
            {
                time++;
                continue;
            }

            if(started[idx]==0)
            {
                rt[idx]=time-at[idx];
                started[idx]=1;
            }

            time++;
            rem[idx]--;

            if(rem[idx]==0)
            {
                completed++;
                ct[idx]=time;
                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];
            }
        }
    }

    float avgwt=0,avgtat=0,avgrt=0;

    printf("\nMultilevel Queue Scheduling\n");
    printf("Queue 1 : Round Robin\n");
    printf("Queue 2 : FCFS\n\n");
    printf("P\tQ\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
        avgwt+=wt[i];
        avgtat+=tat[i];
        avgrt+=rt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,q[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
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

    int at[n],bt[n],q[n];

    for(int i=0;i<n;i++)
    {
        printf("\nProcess P%d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Queue number (1 for RR, 2 for FCFS): ");
        scanf("%d",&q[i]);

        if(q[i]!=1 && q[i]!=2)
        {
            printf("Invalid queue number\n");
            return 0;
        }
    }

    printf("Enter Time Quantum for Queue 1: ");
    scanf("%d",&tq);

    if(tq<=0)
    {
        printf("Invalid Time Quantum\n");
        return 0;
    }

    multilevel_queue(n,at,bt,q,tq);

    return 0;
}
