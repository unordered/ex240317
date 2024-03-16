#include "IocpCore.h"




CIOCP::CIOCP()
    :mIOCPHANDLE(INVALID_HANDLE_VALUE)
{
}

bool CIOCP::ServerInit(std::string pIp, int pPortNumber)
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        LogClass::PrintLog("WSAStartup Error!", WSAGetLastError());
    }

    HANDLE hCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);

    SYSTEM_INFO SystemInfo;
    GetSystemInfo(&SystemInfo);

    for (int i = 0; i < (int)SystemInfo.dwNumberOfProcessors; ++i)
    {
        _beginthreadex(NULL, 0, (_beginthreadex_proc_type)WorkerThread, (LPVOID)hCompletionPort, 0, NULL);
    }

    return false;
}

bool CIOCP::Start()
{
    // 리스너 실행
    return false;
}

int CIOCP::WorkerThread(void)
{
    return 0;
}
