#define SECURITY_WIN32
// #pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "secur32.lib")

#include <windows.h>
#include <security.h>
#include <stdio.h>

void print_error()
{
    DWORD lastError = GetLastError();

    switch (lastError)
    {
    case ERROR_MORE_DATA:
        printf("The output buffer is too small.\n");
        break;
    case ERROR_NO_SUCH_DOMAIN:
        printf("The domain controller is not available to perform the lookup.\n");
        break;
    case ERROR_NONE_MAPPED:
        printf("The user name is not available in the specified format.\n");
        break;
    default:
        printf("Error Code : %d (0x%x)\n", lastError, lastError);
        break;
    }
}

int main()
{
    int nameSize;
    EXTENDED_NAME_FORMAT nameFormat;

    char charBuffer[100];
    wchar_t wcharBuffer[100];

    nameSize = 100;
    printf("GetComputerNameA : ");
    if (GetComputerNameA(charBuffer, &nameSize)) printf("%.*s\n", nameSize, charBuffer);
    else print_error();

    nameSize = 100;
    printf("GetComputerNameW : ");
    if (GetComputerNameW(wcharBuffer, &nameSize)) printf("%.*S\n", nameSize, wcharBuffer);
    else print_error();

    printf("\n");

    for (int i = 0; i < ComputerNameMax; i++)
    {
        nameSize = 100;
        printf("GetComputerNameExA %d : ", i);
        if (GetComputerNameExA((COMPUTER_NAME_FORMAT)i, charBuffer, &nameSize)) printf("%.*s\n", nameSize, charBuffer);
        else print_error();
    }

    printf("\n");

    for (int i = 0; i < ComputerNameMax; i++)
    {
        nameSize = 100;
        printf("GetComputerNameExW %d : ", i);
        if (GetComputerNameExW((COMPUTER_NAME_FORMAT)i, wcharBuffer, &nameSize)) printf("%.*S\n", nameSize, wcharBuffer);
        else print_error();
    }

    printf("\n");

    nameFormat = NameSamCompatible;

    nameSize = 100;
    printf("GetUserNameA : ");
    if (GetUserNameA(charBuffer, &nameSize)) printf("%.*s\n", nameSize, charBuffer);
    else print_error();

    nameSize = 100;
    printf("GetUserNameW : ");
    if (GetUserNameW(wcharBuffer, &nameSize)) printf("%.*S\n", nameSize, wcharBuffer);
    else print_error();

    printf("\n");

    nameSize = 100;
    printf("GetUserNameExA : ");
    if (GetUserNameExA(nameFormat, charBuffer, &nameSize)) printf("%.*s\n", nameSize, charBuffer);
    else print_error();

    nameSize = 100;
    printf("GetUserNameExW : ");
    if (GetUserNameExW(nameFormat, wcharBuffer, &nameSize)) printf("%.*S\n", nameSize, wcharBuffer);
    else print_error();

    nameSize = getchar();
}

