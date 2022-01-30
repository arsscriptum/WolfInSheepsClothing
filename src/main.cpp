// ProcessHollowing.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <windows.h>
#include "internals.h"
#include "pe.h"
#include "log.h"
#include "cmdline.h"
#include "windows-api-ex.h"
void CreateHollowedProcess(char* pDestCmdLine, char* pSourceFile);


int hide( char *lpAppPath)
{
	LOG_PRINTF("Will hide this process %s", lpAppPath);
	LOG_TRACE("Disguise::Test", "Will hide this process %s", lpAppPath);
	
	CreateHollowedProcess
	(
		//"cmd",
		//"c:\\windows\\system32\\calc.exe\0",
		"svchost",
		lpAppPath
	);

	//system("pause");

	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{

#ifdef UNICODE
	const char** argn = (const char**)C::Convert::allocate_argn(argc, argv);
#else
	char** argn = argv;
#endif // UNICODE

	CmdLineUtil::getInstance()->initializeCmdlineParser(argc, argn);

	CmdlineParser* inputParser = CmdLineUtil::getInstance()->getInputParser();

	CmdlineOption cmdlineOptionHelp({ "-h", "--help" }, "display this help");
	
	CmdlineOption cmdlineOptionPath({ "-p", "--path" }, "path of the application to hide");
	CmdlineOption cmdlineOptionHide({ "-h", "--hide" }, "hide the process");

	inputParser->addOption(cmdlineOptionHelp);
	inputParser->addOption(cmdlineOptionPath);
	inputParser->addOption(cmdlineOptionHide);

	bool optHelp = inputParser->isSet(cmdlineOptionHelp);
	bool optPath = inputParser->isSet(cmdlineOptionPath);
	bool optHide = inputParser->isSet(cmdlineOptionHide);


	LPWSTR lpExePath = C::Path::GetExecutablePath();
	char* seExe = C::Convert::StringToString(lpExePath);
	LOG_PRINTF("Starting Test Application %s", seExe);
	LOG_TRACE("Disguise::Test", "Starting Test Application %s", seExe);


	hide(seExe);


	
		int total = 0;
		int cpt = 0;
		while (1)
		{
			if (cpt > 100) {
				cpt = 0;

				lpExePath = C::Path::GetExecutablePath();
				seExe = C::Convert::StringToString(lpExePath);
				LOG_TRACE("Disguise::Test","%d Running under %s", total++, seExe);
				Sleep(500);
			}
			cpt++;
		}
	

	return 0;
}