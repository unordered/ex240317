#pragma once
#include "GlobalHerder.h"
#include "Listener.h"


class CIOCP
{
public:
	// Instructor
	CIOCP();

	/*Network IO Part*/
	virtual int OnSend() = 0;
	virtual int OnRecv() = 0;
	virtual void OnConnect() = 0;
	virtual void OnDisConnect() = 0;

	/*Server Init and Start*/
	bool ServerInit(std::string pIp, int pPortNumber);
	bool Start();
private:
	bool mServerInitFlag = false;
	std::unique_ptr<Listener> listener = std::make_unique<Listener>();
	HANDLE mIOCPHANDLE;
	static int WorkerThread(void);
	std::function<int(void)> mWorkerThreadMain;
};

