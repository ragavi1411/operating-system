#include <stdio.h>
#include <windows.h>

DWORD WINAPI ThreadFunction(LPVOID lpParam)
{
    printf("Hello from Thread\n");
    return 0;
}

int main()
{
    HANDLE hThread;

    hThread = CreateThread(
        NULL,
        0,
        ThreadFunction,
        NULL,
        0,
        NULL
    );

    WaitForSingleObject(hThread, INFINITE);

    printf("Thread completed successfully\n");

    CloseHandle(hThread);

    return 0;
}
