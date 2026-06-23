#include <stdio.h>

int main()
{
    int n, start[20], length[20], i;

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("\nFile\tStart Block\tLength\n");

    for(i = 0; i < n; i++)
    {
        printf("\nEnter start block and length of file %d: ", i + 1);
        scanf("%d%d", &start[i], &length[i]);
    }

    printf("\nFile\tStart Block\tLength\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\n", i + 1, start[i], length[i]);
    }

    return 0;
}
