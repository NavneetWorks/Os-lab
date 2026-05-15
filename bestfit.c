
#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[20];
    int tempBlock[20];

    for (int i = 0; i < m; i++)
        tempBlock[i] = blockSize[i];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    { 
        for (int j = 0; j < m; j++)
        {
            if (tempBlock[j] >= processSize[i])
            {
                allocation[i] = j;
                tempBlock[j] -= processSize[i];
                break;
            }                                                                                                                                                                                                      
        }
    }

    printf("\n--- First Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[20];
    int tempBlock[20];

    for (int i = 0; i < m; i++)
        tempBlock[i] = blockSize[i];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;

        for (int j = 0; j < m; j++)
        {
            if (tempBlock[j] >= processSize[i])
            {
                if (bestIndex == -1 || tempBlock[j] < tempBlock[bestIndex])
                {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1)
        {
            allocation[i] = bestIndex;
            tempBlock[bestIndex] -= processSize[i];
        }
    }

    printf("\n--- Best Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[20];
    int tempBlock[20];

    for (int i = 0; i < m; i++)
        tempBlock[i] = blockSize[i];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int worstIndex = -1;

        for (int j = 0; j < m; j++)
        {
            if (tempBlock[j] >= processSize[i])
            {
                if (worstIndex == -1 || tempBlock[j] > tempBlock[worstIndex])
                {
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1)
        {
            allocation[i] = worstIndex;
            tempBlock[worstIndex] -= processSize[i];
        }
    }

    printf("\n--- Worst Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int m, n;
    int blockSize[20], processSize[20];

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter sizes of %d memory blocks:\n", m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter sizes of %d processes:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processSize[i]);
    }

    firstFit(blockSize, m, processSize, n);
    bestFit(blockSize, m, processSize, n);
    worstFit(blockSize, m, processSize, n);

    return 0;
}
