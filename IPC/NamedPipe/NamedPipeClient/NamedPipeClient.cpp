// NamedPipeClient.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	srand(time(nullptr));

	DWORD wlen = 0;
	Sleep(1000);

	BOOL bRet = WaitNamedPipe(TEXT("\\\\.\\Pipe\\mypipe"), NMPWAIT_WAIT_FOREVER);

	if (!bRet) {
		cout << "Connect the NamedPipe failed." << endl;
		return -1;
	}

	HANDLE hPipe = CreateFile(
		TEXT("\\\\.\\Pipe\\mypipe"),
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if (INVALID_HANDLE_VALUE == hPipe)
		cout << "Open the exit pipe failed." << endl;
	else {
		while (true) {
			char buf[256] = "";
			sprintf_s(buf, "%s%d", buf, rand() % 1000);
			if (!WriteFile(hPipe, buf, sizeof(buf), &wlen, 0)) {
				cout << "Write to pipe failed." << endl;
				break;
			}
			else {
				cout << "To Server: data = " << buf << ",size = " << wlen << endl;
				char rbuf[256] = "";
				DWORD rlen = 0;
				ReadFile(hPipe, rbuf, sizeof(rbuf), &rlen, 0);
				cout << "From Server: data = " << rbuf << ",size = " << rlen << endl;
			}
			Sleep(1000);
		}
		CloseHandle(hPipe);
	}

	system("PAUSE");
    return 0;
}

