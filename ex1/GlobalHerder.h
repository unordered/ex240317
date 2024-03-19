#pragma once
#pragma comment(lib,"ws2_32.lib")
#pragma pack(push, 1)

#include <iostream>
#include <winsock2.h>
#include <Windows.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#include "LogClass.h"
#include <functional>
#include <mutex>

#include <queue>
#include <cassert>
#include <map>
#include "Type.h"
#include "CRingBuffer.h"
#include "Session.h"
#include <MSWSock.h>
#include "Listener.h"

using namespace std;

#ifdef _DEBUG
	#define D_ASSERT(EXPRESSION) aseert(EXPRESSION)
#else // _DEBUG
	#define D_ASSERT(EXPRESSION) __nop(EXPRESSION)
#endif

