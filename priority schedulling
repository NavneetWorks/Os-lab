#include <stdio.h>
#include <limits.h>

struct process
{
    int pid;
    int at;
    int bt;
    int pr;

    int ct;
    int tat;
    int wt;
    int rt;

    int remaining;
    int visited;
};

struct process p[20];
int n;

void non_preemptive_priority()
{
    int completed[20] = {0};
    int time = 0;
    int done = 0;

    while(done != n)
    {
        int idx = -1;
        int highest = INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(p[i].at <= time && completed[i]==0)
            {
                if(p[i].pr < highest)
                {
                    highest = p[i].pr;
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            int start = time;

            p[idx].rt = start - p[idx].at;

            time += p[idx].bt;

            p[idx].ct = time;

            p[idx].tat = p[idx].ct - p[idx].at;

            p[idx].wt = p[idx].tat - p[idx].bt;

            completed[idx] = 1;

            done++;
        }
        else
        {
            time++;
        }
    }

    float avgwt=0,avgtat=0,avgrt=0;

    printf("\nPID AT BT PR CT TAT WT RT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d %d %d %d %d %d %d %d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,
        p[i].ct,p[i].tat,p[i].wt,p[i].rt);

        avgwt += p[i].wt;
        avgtat += p[i].tat;
        avgrt += p[i].rt;
    }

    printf("\nAverage WT = %.2f",avgwt/n);
    printf("\nAverage TAT = %.2f",avgtat/n);
    printf("\nAverage RT = %.2f\n",avgrt/n);
}



void preemptive_priority()
{
    int time=0;
    int complete=0;

    for(int i=0;i<n;i++)
    {
        p[i].remaining = p[i].bt;
        p[i].visited = 0;
    }

    while(complete != n)
    {
        int idx=-1;
        int highest=INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time && p[i].remaining>0)
            {
                if(p[i].pr < highest)
                {
                    highest = p[i].pr;
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            if(p[idx].visited == 0)
            {
                p[idx].rt = time - p[idx].at;
                p[idx].visited = 1;
            }

            p[idx].remaining--;

            time++;

            if(p[idx].remaining == 0)
            {
                complete++;

                p[idx].ct = time;

                p[idx].tat = p[idx].ct - p[idx].at;

                p[idx].wt = p[idx].tat - p[idx].bt;
            }
        }
        else
        {
            time++;
        }
    }

    float avgwt=0,avgtat=0,avgrt=0;

    printf("\nPID AT BT PR CT TAT WT RT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d %d %d %d %d %d %d %d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,
        p[i].ct,p[i].tat,p[i].wt,p[i].rt);

        avgwt += p[i].wt;
        avgtat += p[i].tat;
        avgrt += p[i].rt;
    }

    printf("\nAverage WT = %.2f",avgwt/n);
    printf("\nAverage TAT = %.2f",avgtat/n);
    printf("\nAverage RT = %.2f\n",avgrt/n);
}



int main()
{
    int choice;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        p[i].pid = i+1;

        printf("\nProcess %d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&p[i].at);

        printf("Burst Time: ");
        scanf("%d",&p[i].bt);

        printf("Priority: ");
        scanf("%d",&p[i].pr);
    }

    while(1)
    {
        printf("\n1. Priority Non Preemptive");
        printf("\n2. Priority Preemptive");
        printf("\n3. Exit");

        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                non_preemptive_priority();
                break;

            case 2:
                preemptive_priority();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
