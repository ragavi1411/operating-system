#include <stdio.h>

int main()
{
    int indexBlock, n, blocks[20];
    int i;

    printf("Enter index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks needed: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nIndexed File Allocation\n");
    printf("Index Block: %d\n", indexBlock);

    printf("Allocated Blocks: ");
    for(i = 0; i < n; i++)
        printf("%d ", blocks[i]);

    return 0;
}
