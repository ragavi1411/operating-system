#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char source[100], destination[100];
    char c;

    printf("Enter the source filename: ");
    scanf("%s", source);

    fptr1 = fopen(source, "r");

    if (fptr1 == NULL)
    {
        printf("Cannot open file %s\n", source);
        exit(0);
    }

    printf("Enter the destination filename: ");
    scanf("%s", destination);

    fptr2 = fopen(destination, "w");

    if (fptr2 == NULL)
    {
        printf("Cannot open file %s\n", destination);
        fclose(fptr1);
        exit(0);
    }

    while ((c = fgetc(fptr1)) != EOF)
    {
        fputc(c, fptr2);
    }

    printf("\nContents copied successfully to %s\n", destination);

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}
