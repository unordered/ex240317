#pragma once
#include "GlobalHerder.h"

class CRevolver
{
public:
	static CRevolver __singleton;

	queue<Bullet*> mDbQueue;
	queue<Bullet*> mLogQueue;
	priority_queue<unsigned int, Bullet*> mStartQueue;

};

/*
Bullet�� DB�� �α� Ȥ�� �ý��� �޽����� �ǹ��Ѵ�.
TYPE			 1byte
LENGTH			 2byte
MESSAGE POINGER	 4byte
*/
class Bullet
{
public:
	enum class BulletType
	{
		TR,
		LOG,
		DB,
		SYS
	};

	using BULLET_TYPE = unsigned char;
	using BULLET_MESSAGE_LENGTH = unsigned short;
	using BULLET_MESSAGE_POINTER = char*;

	BULLET_TYPE mType;
	BULLET_MESSAGE_LENGTH mMessageLength;
	BULLET_MESSAGE_POINTER mMessagePtr;
};

// Bullet Pool
class BulletPool
{
public:
	Bullet* GetBullet();
};