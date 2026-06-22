#include <stdio.h>
#include <windows.h>

int data = 0;

DWORD WINAPI reader(LPVOID arg)
{
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("Reader reads data: %d\n", data);
        Sleep(500);
    }

    return 0;
}

DWORD WINAPI writer(LPVOID arg)
{
    int i;

    for(i = 0; i < 5; i++)
    {
        data++;
        printf("Writer writes data: %d\n", data);
        Sleep(500);
    }

    return 0;
}

int main()
{
    HANDLE readerThread, writerThread;

    readerThread = CreateThread(NULL, 0, reader, NULL, 0, NULL);
    writerThread = CreateThread(NULL, 0, writer, NULL, 0, NULL);

    WaitForSingleObject(readerThread, INFINITE);
    WaitForSingleObject(writerThread, INFINITE);

    CloseHandle(readerThread);
    CloseHandle(writerThread);

    return 0;
}
