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
	//	// staitc 변수로 선언함으로서, instance 뱐수는 한번만 초기화되고, 프로그램 수명 내내 지속됨.
	//	// 특히 C++11부터 thread-safe 변수 초기화가 보장됨.
	//	static SessionManager instance;
	//	return instance;
	//}


	void InitSessionManager(int pClientCount);
private:
	// Default 생성자 사용
	SessionManager() = default;
	

	//// 객체는 유일하게 하나만 생성되어야 하기에 복사(대입), 이동(대입) 생성자 비활성화
	//// 복사, 이동 생성자를 delete로 선언함으로서, 
	//// 프로그래머 실수에 의한 복사, 이동 생성자 호출을 원천에 방지할 수 있음.
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