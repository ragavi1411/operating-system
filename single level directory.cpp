#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, choice;
    char file[20][20], fname[20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter file %d name: ", i + 1);
        scanf("%s", file[i]);
    }

    do
    {
        printf("\n1. Display Files");
        printf("\n2. Search File");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nFiles in Directory:\n");
                for(i = 0; i < n; i++)
                    printf("%s\n", file[i]);
                break;

            case 2:
                printf("Enter file name to search: ");
                scanf("%s", fname);

                for(i = 0; i < n; i++)
                {
                    if(strcmp(file[i], fname) == 0)
                    {
                        printf("File Found\n");
                        break;
                    }
                }

                if(i == n)
                    printf("File Not Found\n");
                break;

            case 3:
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 3);

    return 0;
}
