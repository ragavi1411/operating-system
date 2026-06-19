#include <stdio.h>

int main()
{
    int i, n, time, remain, tq;
    int bt[20], rt[20];
    int wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    time = 0;
    i = 0;

    while(remain != 0)
    {
        if(rt[i] <= tq && rt[i] > 0)
        {
            time += rt[i];
            rt[i] = 0;
            remain--;

            printf("P%d\tWT = %d\tTAT = %d\n",
                   i + 1,
                   time - bt[i],
                   time);

            wt += time - bt[i];
            tat += time;
        }
        else if(rt[i] > 0)
        {
            rt[i] -= tq;
            time += tq;
        }

        if(i == n - 1)
            i = 0;
        else
            i++;
    }

    printf("\nAverage Waiting Time = %.2f",
           (float)wt / n);
    printf("\nAverage Turnaround Time = %.2f\n",
           (float)tat / n);

    return 0;
}
