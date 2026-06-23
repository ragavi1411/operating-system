#include <stdio.h>

int main()
{
    int pages[50], frame[10], time[10];
    int n, f, i, j, faults = 0, count = 0;
    int found, pos, min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            min = time[0];
            pos = 0;

            for(j = 1; j < f; j++)
            {
                if(time[j] < min)
                {
                    min = time[j];
                    pos = j;
                }
            }

            count++;
            frame[pos] = pages[i];
            time[pos] = count;
            faults++;
        }
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}#include <stdio.h>

int main()
{
    int pages[50], frame[10], time[10];
    int n, f, i, j, faults = 0, count = 0;
    int found, pos, min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            min = time[0];
            pos = 0;

            for(j = 1; j < f; j++)
            {
                if(time[j] < min)
                {
                    min = time[j];
                    pos = j;
                }
            }

            count++;
            frame[pos] = pages[i];
            time[pos] = count;
            faults++;
        }
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
