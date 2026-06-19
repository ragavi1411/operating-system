#include <stdio.h>
#include <conio.h>

int main()
{
    int i;

    printf("\nDINING PHILOSOPHER PROBLEM\n");

    for(i = 1; i <= 5; i++)
    {
        printf("\nPhilosopher %d is THINKING", i);

        printf("\nPhilosopher %d is HUNGRY", i);

        printf("\nPhilosopher %d takes Fork %d and Fork %d",
               i, i, (i % 5) + 1);

        printf("\nPhilosopher %d is EATING", i);

        printf("\nPhilosopher %d puts down Fork %d and Fork %d",
               i, i, (i % 5) + 1);

        printf("\nPhilosopher %d starts THINKING again\n", i);
    }

    getch();
    return 0;
}
