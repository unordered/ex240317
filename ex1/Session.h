#pragma once
#include "GlobalHerder.h"

struct WSAOVERLAPPEDEX
{
	WSAOVERLAPPED overlapped;
	TR_TYPE type;
};

class Session
{
private:
	unsigned int mSessionID;
	SOCKET mSocket;

	char addressBuf[1024];
	const int outBufLen = 1024;


	WSAOVERLAPPEDEX mSendOVERLAEEPD;
	WSAOVERLAPPEDEX mRecvOVERLAEEPD;
	WSAOVERLAPPEDEX mAcceptOVERLAEEPD;
	RingBuffer mSendQ;
	RingBuffer mRecvQ;

	time_t mLastRecvTime;
	mutex mMutex;

	int IO_COUNT;

public:
	Session()
	{
		mSendOVERLAEEPD.type = TR_TYPE::SEND;
		mRecvOVERLAEEPD.type = TR_TYPE::RECV;
		mAcceptOVERLAEEPD.type = TR_TYPE::ACCPET;

	}
	SOCKET SetSocket(SOCKET pSocket);
	void SendPost(char* pDate, int pLen);
	void RecvPost();
	char* getOutputBuffer();
	const int getOutBufferSize();
	WSAOVERLAPPEDEX& getmAcceptOVERLAEEPD();
	int GetSessionID();

	int ACCPET_COMPLETION(unsigned short pLen);
	int RECV_COMPLETION(int pLen);
	int SEND_COMPLETION(int pLen);
	
	int RecvRemainingDataNumber();
	int ReadData(int pReadSize);
	void RealeaseSession();
	PACKET_HEADER* GetRecvBufferDataHEADER();

};

class SessionManager
{
	static unsigned long mSessionID;
	
public:
	//static SessionManager& GetInstance() {
	//	// staitc ������ ���������μ�, instance ������ �ѹ��� �ʱ�ȭ�ǰ�, ���α׷� ���� ���� ���ӵ�.
	//	// Ư�� C++11���� thread-safe ���� �ʱ�ȭ�� �����.
	//	static SessionManager instance;
	//	return instance;
	//}


	void InitSessionManager(int pClientCount);
private:
	// Default ������ ���
	SessionManager() = default;
	

	//// ��ü�� �����ϰ� �ϳ��� �����Ǿ�� �ϱ⿡ ����(����), �̵�(����) ������ ��Ȱ��ȭ
	//// ����, �̵� �����ڸ� delete�� ���������μ�, 
	//// ���α׷��� �Ǽ��� ���� ����, �̵� ������ ȣ���� ��õ�� ������ �� ����.
	//SessionManager(const SessionManager&) = delete;
	//SessionManager& operator=(const SessionManager&) = delete;
	//SessionManager(SessionManager&&) = delete;
	//SessionManager& operator=(SessionManager&&) = delete;
public:


	// Session* FindSession(int pSessionID);
	// bool Release(int pSessionID);
	// Session* GetSession();
	queue<Session*> mSessionQ;
	Listener mListner;

};