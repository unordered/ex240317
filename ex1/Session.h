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
		// staitc ������ ���������μ�, instance ������ �ѹ��� �ʱ�ȭ�ǰ�, ���α׷� ���� ���� ���ӵ�.
		// Ư�� C++11���� thread-safe ���� �ʱ�ȭ�� �����.
		static SessionManage instance;
		return instance;
	}

private:
	// Default ������ ���
	SessionManage() = default;

	// ��ü�� �����ϰ� �ϳ��� �����Ǿ�� �ϱ⿡ ����(����), �̵�(����) ������ ��Ȱ��ȭ
	// ����, �̵� �����ڸ� delete�� ���������μ�, 
	// ���α׷��� �Ǽ��� ���� ����, �̵� ������ ȣ���� ��õ�� ������ �� ����.
	SessionManage(const SessionManage&) = delete;
	SessionManage& operator=(const SessionManage&) = delete;
	SessionManage(SessionManage&&) = delete;
	SessionManage& operator=(SessionManage&&) = delete;
public:


	// Session* FindSession(int pSessionID);
	// bool Release(int pSessionID);
	// Session* GetSession();

};