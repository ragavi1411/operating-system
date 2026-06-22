#include <stdio.h>
#include <windows.h>

LONG counter = 0;
HANDLE mutex;

DWORD WINAPI threadFunction(LPVOID arg)
{
    int i;

    for(i = 0; i < 100000; i++)
    {
        WaitForSingleObject(mutex, INFINITE);

        counter++;

        ReleaseMutex(mutex);
    }

    return 0;
}

int main()
{
    HANDLE thread1, thread2;

    mutex = CreateMutex(NULL, FALSE, NULL);

    thread1 = CreateThread(NULL, 0, threadFunction, NULL, 0, NULL);
    thread2 = CreateThread(NULL, 0, threadFunction, NULL, 0, NULL);

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    printf("Final counter value: %ld\n", counter);

    CloseHandle(thread1);
    CloseHandle(thread2);
    CloseHandle(mutex);

    return 0;
}
