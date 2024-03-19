#pragma once
#include "GlobalHerder.h"
#include "Listener.h"


class CIOCP
{
public:
	// Instructor
	CIOCP();

	/*Network IO Part*/
	virtual int OnSend(int pSendedByte) = 0;
	virtual int OnRecv(int pSessionId, PACKET_HEADER* header) = 0;
	virtual void OnConnect(int pSessionId) = 0;
	virtual void OnDisConnect(int pSessionId) = 0;

	/*Server Init and Start*/
	bool ServerInit(std::string pIp, int pPortNumber);
	bool Start(int pWorkerThreadNumber);
private:
	bool mServerInitFlag = false;
	std::unique_ptr<Listener> listener = std::make_unique<Listener>();
	HANDLE mIOCPHANDLE;

	int WorkerThread(void);
	void PacketProcesser(Session* session);
	std::function<int(void)> mWorkerThreadMain;

	SessionManager mSessionManager;
	 
	std::thread workerThread[5];
	
};

