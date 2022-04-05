// NamedPipeServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	srand(time(nullptr));

	char buf[256] = "";
	DWORD rlen = 0;
	HANDLE hPipe = CreateNamedPipe(
		TEXT("\\\\.\\Pipe\\myPipe"),
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
		PIPE_UNLIMITED_INSTANCES,
		0,
		0,
		NMPWAIT_WAIT_FOREVER,
		NULL
		);

	if (INVALID_HANDLE_VALUE == hPipe)
		cout << "Create NamedPipe failed:" << GetLastError() << endl;
	else {
		cout << "Waiting for client connection..." << endl;

		if (!ConnectNamedPipe(hPipe, nullptr))
			cout << "Connection failed!" << endl;
		else
			cout << "Connection success!" << endl;

		while (true) {
			if (!ReadFile(hPipe, buf, 256, &rlen, nullptr)) {
				cout << "Read data from NamedPipe failed." << endl;
				break;
			}
			else {
				cout << "From client: data = " << buf << ",size = " << rlen << endl;
				
				char wbuf[256] = "";
				sprintf_s(wbuf, "%s%d", wbuf, rand() % 1000);
				DWORD wlen = 0;
				WriteFile(hPipe, wbuf, sizeof(wbuf), &wlen, 0);
				
				cout << "To Client: data = " << wbuf << ",size = " << wlen;
				Sleep(1000);
			}
		}
		CloseHandle(hPipe);
	}

	system("PAUSE");
    return 0;
}

