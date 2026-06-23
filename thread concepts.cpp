#include <stdio.h>
#include <windows.h>

DWORD WINAPI myThread(LPVOID arg)
{
    printf("Thread is running...\n");
    Sleep(1000);
    printf("Thread completed.\n");
    return 0;
}

int main()
{
    HANDLE thread;

    thread = CreateThread(NULL, 0, myThread, NULL, 0, NULL);

    WaitForSingleObject(thread, INFINITE);

    printf("Main thread completed.\n");

    CloseHandle(thread);

    return 0;
}
