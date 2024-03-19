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

bool CIOCP::Start(int pWorkerThreadNumber)
{
    WSADATA wsaData;
    int iResult = 0;
    BOOL bRetVal = FALSE;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"Error at WSAStartup\n");
        return 1;
    }

    mSessionManager.InitSessionManager(2500);

    // ������ ����
    listener->AddressSetting("127.0.0.1", 15555);
    listener->Listen(mIOCPHANDLE);
    
    for (int i = 0; i < 5; i++)
    {
        workerThread[i] = std::thread([&] {  WorkerThread(); });
    }

    for (int i = 0; i < 5; i++)
    {
        workerThread[i].join();
    }

    return false;
}

int CIOCP::WorkerThread(void)
{
    // IOCP �ʱ�ȭ ���� Ȯ��



    DWORD NumberOfBytesTransferred;
    Session* session;
    WSAOVERLAPPEDEX overlapped;
    // 
    while (true)
    {
        // GQCS 
        int iocpReturnValue = GetQueuedCompletionStatus(mIOCPHANDLE, &NumberOfBytesTransferred, (PULONG_PTR)session, (LPOVERLAPPED*)&overlapped, NULL);

        if (iocpReturnValue == 0)
        {
            continue;
        }

        // ����ã��
        switch (overlapped.type)
        {
        case (TR_TYPE::ACCPET):
            session->ACCPET_COMPLETION(NumberOfBytesTransferred);
            break;
        case (TR_TYPE::RECV):
            session->RECV_COMPLETION(NumberOfBytesTransferred);
            PacketProcesser(session);   
            break;
        case (TR_TYPE::SEND):
            session->SEND_COMPLETION(NumberOfBytesTransferred);
            break;
        case (TR_TYPE::OTHER):
            LogClass::PrintLog("TR_TYPE::OTHER");
            break;
        default:
            break;
        }
    }

    


    return 0;
}

void CIOCP::PacketProcesser(Session* session)
{
    PACKET_HEADER* header;
    while (session->RecvRemainingDataNumber() < sizeof(PACKET_HEADER))
    {
        header = session->GetRecvBufferDataHEADER();
        if (header->packetLen <= session->RecvRemainingDataNumber() + sizeof(PACKET_HEADER))
        {
            // �����ϰ� ��Ŷ �ϳ��� �ϼ��� ��Ȳ�̴�. 
            // ��Ŷ�� ���絵 �ȴ�.
            int processLen = OnRecv(session->GetSessionID(), header);
            if (session->ReadData(processLen) == false)
            {
                session->RealeaseSession();
            }

        }
    }

    session->RecvPost();
}
