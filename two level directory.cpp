#include <stdio.h>
#include <string.h>

struct directory
{
    char dirname[20];
    char filename[20][20];
    int filecount;
};

int main()
{
    struct directory dir[10];
    int nd, i, j;

    printf("Enter number of directories: ");
    scanf("%d", &nd);

    for(i = 0; i < nd; i++)
    {
        printf("\nEnter directory name: ");
        scanf("%s", dir[i].dirname);

        printf("Enter number of files in %s: ", dir[i].dirname);
        scanf("%d", &dir[i].filecount);

        for(j = 0; j < dir[i].filecount; j++)
        {
            printf("Enter file %d name: ", j + 1);
            scanf("%s", dir[i].filename[j]);
        }
    }

    printf("\nDirectory Structure\n");

    for(i = 0; i < nd; i++)
    {
        printf("\nDirectory: %s\n", dir[i].dirname);

        for(j = 0; j < dir[i].filecount; j++)
        {
            printf("  %s\n", dir[i].filename[j]);
        }
    }

    return 0;
}
