#include "Session.h"

void SessionManager::InitSessionManager(int pClientCount)
{
	// 技记 积己
	Session* temp = new Session();
	SOCKET sessionsock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	temp->SetSocket(sessionsock);
	AcceptEx(mListner.GetListenSocket(), sessionsock,
		temp->getOutputBuffer(), temp->getOutBufferSize() - ((sizeof(sockaddr_in) + 16) * 2),
		sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, NULL, (LPOVERLAPPED)(&temp->getmAcceptOVERLAEEPD()));

	
	// IOCP 钮客 楷搬
	
	// IOCP ACEEPTEX

	mSessionQ.push(new Session());
}

void Session::SendPost(char* pDate, int pLen)
{
	LPWSABUF buffers;
	//buffers->buf[0] = mSendQ.GetWriteBufferPtr();
	//buffers->len = mSendQ.GetNotBrokenPutSize();
	//buffers->buf[1] = mSendQ

	//WSASend(mSocket, mSendQ.GetWriteBufferPtr(),1,mSendQ.GetNotBrokenPutSize(),NULL, mSendOVERLAEEPD
	//)
}

void Session::RecvPost()
{
}
