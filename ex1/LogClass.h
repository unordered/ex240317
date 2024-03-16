#pragma once
#include "GlobalHerder.h"

class LogClass
{
public:
	static void PrintLog(std::string pLogMessage);
	static void PrintLog(std::string pLogMessage, int pErrorCode);
	static LogClass mLogClass;
};