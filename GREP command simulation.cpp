#include <stdio.h>
#include <string.h>

int main()
{
    char text[100][100], word[50];
    int n, i;

    printf("Enter number of lines: ");
    scanf("%d", &n);
    getchar();

    printf("Enter lines:\n");
    for(i = 0; i < n; i++)
        gets(text[i]);

    printf("Enter word to search: ");
    gets(word);

    printf("\nMatching Lines:\n");

    for(i = 0; i < n; i++)
    {
        if(strstr(text[i], word) != NULL)
            printf("%s\n", text[i]);
    }

    return 0;
}#include <stdio.h>

int mutex = 1;
int full = 0;
int empty = 5, x = 0;

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces item %d", x);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d", x);
    x--;
    mutex = signal(mutex);
}

int main()
{
    int n;

    printf("\n1. Producer");
    printf("\n2. Consumer");
    printf("\n3. Exit");

    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch(n)
        {
            case 1:
                if((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer Full!");
                break;

            case 2:
                if((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer Empty!");
                break;

            case 3:
                return 0;

            default:
                printf("Invalid Choice");
        }
    }

    return 0;
}
