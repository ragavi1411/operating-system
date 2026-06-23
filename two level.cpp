#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[20], n, head, i;
    int seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++)
    {
        seek += abs(req[i] - head);
        head = req[i];
    }

    printf("Total Seek Time = %d", seek);

    return 0;
}
