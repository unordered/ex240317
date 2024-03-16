#pragma once
#include "IocpCore.h"


class ChatServer : public CIOCP
{
public:
	virtual int OnSend();
	virtual int OnRecv();
	virtual void OnConnect();
	virtual void OnDisConnect();
	virtual bool Start();
}