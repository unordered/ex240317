#pragma once
#pragma comment(lib,"ws2_32.lib")

#include <iostream>
#include <Windows.h>
#include <winsock.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#include "LogClass.h"
#include <functional>

#include <queue>
#include <cassert>
#include <map>

using namespace std;

#ifdef _DEBUG
	#define D_ASSERT(EXPRESSION) aseert(EXPRESSION)
#else // _DEBUG
	#define D_ASSERT(EXPRESSION) __nop(EXPRESSION)
#endif

