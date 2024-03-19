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


	// 객체는 유일하게 하나만 생성되어야 하기에 복사(대입), 이동(대입) 생성자 비활성화
	// 복사, 이동 생성자를 delete로 선언함으로서, 
	// 프로그래머 실수에 의한 복사, 이동 생성자 호출을 원천에 방지할 수 있음.
	Listener(const Listener&) = delete;
	Listener& operator=(const Listener&) = delete;
	Listener(Listener&&) = delete;
	Listener& operator=(Listener&&) = delete;
};