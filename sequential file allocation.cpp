#include <stdio.h>

int main()
{
    int f[50], i, st, len, j;

    for(i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter starting block: ");
    scanf("%d", &st);

    printf("Enter length of file: ");
    scanf("%d", &len);

    for(j = st; j < st + len; j++)
    {
        if(f[j] == 0)
            f[j] = 1;
        else
        {
            printf("Block already allocated\n");
            return 0;
        }
    }

    printf("\nFile Allocated Successfully\n");
    printf("Allocated Blocks: ");

    for(j = st; j < st + len; j++)
        printf("%d ", j);

    return 0;

