#include <stdio.h>

int main()
{
    int blockSize[10], processSize[10];
    int allocation[10];
    int nb, np, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter sizes of processes:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &processSize[i]);

    for(i = 0; i < np; i++)
        allocation[i] = -1;

    for(i = 0; i < np; i++)
    {
        for(j = 0; j < nb; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");

    for(i = 0; i < np; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
