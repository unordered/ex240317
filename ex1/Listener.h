#pragma once
#include "GlobalHerder.h"

class Listener
{
	
public:

	static Listener* GetListner()
	{
		return &mListner;
	}


	void AddressSetting(std::string ip, int port)
	{
		
	}

	int Listen(HANDLE pIOCPHANDLE)
	{
		CreateIoCompletionPort((HANDLE)mListenSock, pIOCPHANDLE, (ULONG_PTR)0, 0);
		return listen(mListenSock, 1000);
	}

	SOCKET GetListenSocket()
	{
		return mListenSock;
	}

	static Listener mListner;
	SOCKET mListenSock;


private:
	Listener() = default;


	// ��ü�� �����ϰ� �ϳ��� �����Ǿ�� �ϱ⿡ ����(����), �̵�(����) ������ ��Ȱ��ȭ
	// ����, �̵� �����ڸ� delete�� ���������μ�, 
	// ���α׷��� �Ǽ��� ���� ����, �̵� ������ ȣ���� ��õ�� ������ �� ����.
	Listener(const Listener&) = delete;
	Listener& operator=(const Listener&) = delete;
	Listener(Listener&&) = delete;
	Listener& operator=(Listener&&) = delete;
};