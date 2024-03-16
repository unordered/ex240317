#include "LogClass.h"

void LogClass::PrintLog(std::string pLogMessage)
{
	#ifdef _DEBUG
	std::cout << pLogMessage << std::endl;
	#endif
}

void LogClass::PrintLog(std::string pLogMessage, int pErrorCode)
{
#ifdef _DEBUG
	std::cout << pLogMessage << "Error Code: "<< pErrorCode << std::endl;
#endif
}

