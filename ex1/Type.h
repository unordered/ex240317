#pragma once

enum class TR_TYPE
{
	SEND =0,
	RECV =1,
	ACCPET =2,
	OTHER = 3
};

struct PACKET_HEADER
{
public:
	unsigned short packetLen;
};

struct PAKCET_ECHO : public PACKET_HEADER
{
public:
	char message[8];
};

