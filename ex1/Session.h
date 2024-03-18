#pragma once
#include "GlobalHerder.h"

class Session
{
private:
	unsigned int mSessionID;
	SOCKET mSocket;

	// CRingBuffer mSendQ;
	// CRingBuffer mRecvQ;

	// time_t mLastRecvTime;
	// Mutex mMutex;
	
};

class SessionManage
{
	static unsigned long mSessionID;
	
public:
	static SessionManage& GetInstance() {
		// staitc 변수로 선언함으로서, instance 뱐수는 한번만 초기화되고, 프로그램 수명 내내 지속됨.
		// 특히 C++11부터 thread-safe 변수 초기화가 보장됨.
		static SessionManage instance;
		return instance;
	}

private:
	// Default 생성자 사용
	SessionManage() = default;

	// 객체는 유일하게 하나만 생성되어야 하기에 복사(대입), 이동(대입) 생성자 비활성화
	// 복사, 이동 생성자를 delete로 선언함으로서, 
	// 프로그래머 실수에 의한 복사, 이동 생성자 호출을 원천에 방지할 수 있음.
	SessionManage(const SessionManage&) = delete;
	SessionManage& operator=(const SessionManage&) = delete;
	SessionManage(SessionManage&&) = delete;
	SessionManage& operator=(SessionManage&&) = delete;
public:


	// Session* FindSession(int pSessionID);
	// bool Release(int pSessionID);
	// Session* GetSession();

};