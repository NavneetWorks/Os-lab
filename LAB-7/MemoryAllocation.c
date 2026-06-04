#include <stdio.h>

void display(char name[], int np, int process[], int allocation[])
{
    printf("\n--- %s ---\n", name);
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(int i=0;i<np;i++)
    {
        if(allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i+1, process[i], allocation[i]+1);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, process[i]);
    }
}

void first_fit(int nb, int blockSize[], int np, int process[], int allocation[])
{
    int used[nb];

    for(int i=0;i<nb;i++)
        used[i]=0;

    for(int i=0;i<np;i++)
    {
        allocation[i]=-1;

        for(int j=0;j<nb;j++)
        {
            if(used[j]==0 && blockSize[j]>=process[i])
            {
                allocation[i]=j;
                used[j]=1;
                break;
            }
        }
    }
}

void best_fit(int nb, int blockSize[], int np, int process[], int allocation[])
{
    int used[nb];

    for(int i=0;i<nb;i++)
        used[i]=0;

    for(int i=0;i<np;i++)
    {
        int best=-1;
        allocation[i]=-1;

        for(int j=0;j<nb;j++)
        {
            if(used[j]==0 && blockSize[j]>=process[i])
            {
                if(best==-1 || blockSize[j]<blockSize[best])
                    best=j;
            }
        }

        if(best!=-1)
        {
            allocation[i]=best;
            used[best]=1;
        }
    }
}

void worst_fit(int nb, int blockSize[], int np, int process[], int allocation[])
{
    int used[nb];

    for(int i=0;i<nb;i++)
        used[i]=0;

    for(int i=0;i<np;i++)
    {
        int worst=-1;
        allocation[i]=-1;

        for(int j=0;j<nb;j++)
        {
            if(used[j]==0 && blockSize[j]>=process[i])
            {
                if(worst==-1 || blockSize[j]>blockSize[worst])
                    worst=j;
            }
        }

        if(worst!=-1)
        {
            allocation[i]=worst;
            used[worst]=1;
        }
    }
}

int main()
{
    int nb,np;

    printf("Enter number of memory blocks: ");
    scanf("%d",&nb);

    int blockSize[nb];

    printf("Enter sizes of %d memory blocks:\n",nb);
    for(int i=0;i<nb;i++)
        scanf("%d",&blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d",&np);

    int process[np];

    printf("Enter sizes of %d processes:\n",np);
    for(int i=0;i<np;i++)
        scanf("%d",&process[i]);

    int first[np],best[np],worst[np];

    first_fit(nb,blockSize,np,process,first);
    best_fit(nb,blockSize,np,process,best);
    worst_fit(nb,blockSize,np,process,worst);

    display("First Fit",np,process,first);
    display("Best Fit",np,process,best);
    display("Worst Fit",np,process,worst);

    return 0;
}
