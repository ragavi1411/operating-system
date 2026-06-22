#include <stdio.h>

#define MAX_MEMORY 1000

int memory[MAX_MEMORY];

void initializeMemory()
{
    int i;
    for(i = 0; i < MAX_MEMORY; i++)
        memory[i] = -1;
}

void displayMemory()
{
    int i, j;

    printf("\nMemory Status:\n");

    for(i = 0; i < MAX_MEMORY; i++)
    {
        if(memory[i] == -1)
        {
            j = i;

            while(j < MAX_MEMORY && memory[j] == -1)
                j++;

            printf("Free Memory Block %d - %d\n", i, j - 1);

            i = j - 1;
        }
    }
}

void allocateMemory(int processId, int size)
{
    int bestStart = -1;
    int bestSize = MAX_MEMORY + 1;
    int currentStart = -1;
    int currentSize = 0;
    int i;

    for(i = 0; i <= MAX_MEMORY; i++)
    {
        if(i < MAX_MEMORY && memory[i] == -1)
        {
            if(currentSize == 0)
                currentStart = i;

            currentSize++;
        }
        else
        {
            if(currentSize >= size && currentSize < bestSize)
            {
                bestSize = currentSize;
                bestStart = currentStart;
            }

            currentSize = 0;
        }
    }

    if(bestStart != -1)
    {
        for(i = bestStart; i < bestStart + size; i++)
            memory[i] = processId;

        printf("Allocated memory block %d-%d to Process %d\n",
               bestStart, bestStart + size - 1, processId);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
}

void deallocateMemory(int processId)
{
    int i;

    for(i = 0; i < MAX_MEMORY; i++)
    {
        if(memory[i] == processId)
            memory[i] = -1;
    }

    printf("Memory released by Process %d\n", processId);
}

int main()
{
    initializeMemory();

    displayMemory();

    allocateMemory(1, 200);
    allocateMemory(2, 300);

    displayMemory();

    deallocateMemory(1);

    displayMemory();

    allocateMemory(3, 150);

    displayMemory();

    return 0;
}
