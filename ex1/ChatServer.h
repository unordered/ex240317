#pragma once
#include "IocpCore.h"
#include "ContentGlobalHeader.h"

class ChatServer : public CIOCP
{
public:
	virtual int OnSend();
	virtual int OnRecv(unsigned int pSessionId, unsigned short pPacketLenth, BYTE* pPacketDate)
	{
		// mPacketProcess->packetProcess(pSessionId, pPacketLenth, pPacketDate);
	}
	virtual void OnConnect();
	virtual void OnDisConnect();
	virtual bool Init();

private:
	//unique_ptr<CRevolver> mCRevoler = std::make_ptr<CRevoler>();
	//unique_ptr<PacketProcess> mPacketProcess = std::make_ptr<PacketProcess>();
};

class PacketProcess
{
public:
	void Init()
	{
		mMessageFunctions[(int)CS_LOGIN] = func1;
		mMessageFunctions[(int)SC_LOGIN] = func1;
		mMessageFunctions[(int)CS_LOGOUT] = func1;
		mMessageFunctions[(int)SC_LOGOUT] = func1;
		mMessageFunctions[(int)CS_ROOM_ENTHER_5] = func1;

	}


	enum PACKET_TYPE
	{
		CS_LOGIN = 1,
		SC_LOGIN = 2,
		CS_LOGOUT = 3,
		SC_LOGOUT = 4,
		CS_ROOM_ENTHER_5,
		//...
	};

	int packetProcess(unsigned int pSessionId, unsigned short pPacketLenth, BYTE* pPacketDate)
	{
		// type뽑아내기
		int type = 1;
		// 존재하는 타입인지 확인

		auto iter = mMessageFunctions.find(type);
		if (iter != mMessageFunctions.end()) {
			auto k = iter->second;
			(this->*(iter->second))(pSessionId, pPacketLenth, pPacketDate);

		}
		// if(type ==true)

	}
	int func1(unsigned int, unsigned short, BYTE*);
	int func2(unsigned int, unsigned short, BYTE*);
	int func3(unsigned int, unsigned short, BYTE*);
	int func4(unsigned int, unsigned short, BYTE*);
	int func5(unsigned int, unsigned short, BYTE*);

	//typedef int(PacketProcess::* PROCESS_RECV_PACKET_FUNCTION)(unsigned int, unsigned short, BYTE*);
	unordered_map<int,int(PacketProcess::*)(unsigned int, unsigned short, BYTE*)> mMessageFunctions;
	//std::unordered_map<int, PROCESS_RECV_PACKET_FUNCTION> mMessageFunctions;
};

