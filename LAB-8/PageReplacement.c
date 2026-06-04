#include <stdio.h>

int is_present(int frames[], int f, int page)
{
    for(int i=0;i<f;i++)
    {
        if(frames[i]==page)
            return 1;
    }

    return 0;
}

int fifo(int pages[], int n, int f)
{
    int frames[10];
    int next=0,faults=0;

    for(int i=0;i<f;i++)
        frames[i]=-1;

    for(int i=0;i<n;i++)
    {
        if(!is_present(frames,f,pages[i]))
        {
            frames[next]=pages[i];
            next=(next+1)%f;
            faults++;
        }
    }

    return faults;
}

int lru(int pages[], int n, int f)
{
    int frames[10],lastUsed[10];
    int faults=0;

    for(int i=0;i<f;i++)
    {
        frames[i]=-1;
        lastUsed[i]=-1;
    }

    for(int i=0;i<n;i++)
    {
        int found=0;

        for(int j=0;j<f;j++)
        {
            if(frames[j]==pages[i])
            {
                found=1;
                lastUsed[j]=i;
                break;
            }
        }

        if(!found)
        {
            int pos=0;

            for(int j=1;j<f;j++)
            {
                if(lastUsed[j]<lastUsed[pos])
                    pos=j;
            }

            frames[pos]=pages[i];
            lastUsed[pos]=i;
            faults++;
        }
    }

    return faults;
}

int optimal(int pages[], int n, int f)
{
    int frames[10];
    int faults=0;

    for(int i=0;i<f;i++)
        frames[i]=-1;

    for(int i=0;i<n;i++)
    {
        if(!is_present(frames,f,pages[i]))
        {
            int pos=-1,farthest=-1;

            for(int j=0;j<f;j++)
            {
                int nextUse=-1;

                for(int k=i+1;k<n;k++)
                {
                    if(frames[j]==pages[k])
                    {
                        nextUse=k;
                        break;
                    }
                }

                if(nextUse==-1)
                {
                    pos=j;
                    break;
                }

                if(nextUse>farthest)
                {
                    farthest=nextUse;
                    pos=j;
                }
            }

            frames[pos]=pages[i];
            faults++;
        }
    }

    return faults;
}

int main()
{
    int pages[20],n,f;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    printf("Enter pages: ");
    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    printf("\nFIFO Faults    = %d",fifo(pages,n,f));
    printf("\nLRU Faults     = %d",lru(pages,n,f));
    printf("\nOptimal Faults = %d\n",optimal(pages,n,f));

    return 0;
}
