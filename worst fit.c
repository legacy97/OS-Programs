#include <stdio.h>

int main()
{
    int blockSize[20], processSize[20];
    int allocation[20];
    int m, n, i, j, worstIdx;

    // Input number of memory blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    // Input sizes of memory blocks
    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &blockSize[i]);
    }

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input sizes of processes
    printf("Enter sizes of processes:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &processSize[i]);
    }

    // Initially no block is allocated
    for(i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    // Worst-Fit Allocation
    for(i = 0; i < n; i++)
    {
        worstIdx = -1;

        for(j = 0; j < m; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                if(worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }

        // If suitable block found
        if(worstIdx != -1)
        {
            allocation[i] = worstIdx;

            // Reduce available memory in that block
            blockSize[worstIdx] -= processSize[i];
        }
    }

    // Display allocation result
    printf("\nProcess No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
        {
            printf("%d\n", allocation[i] + 1);
        }
        else
        {
            printf("Not Allocated\n");
        }
    }

    return 0;
}
