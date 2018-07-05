//#include "socket.h"

#include <iostream>
#include "socket-lib\socket-lib.h"

#pragma comment(lib, "socket-lib.lib")

void main(int cnt, char ** str)
{
	SetConsoleTitleA("Åu.ÅvÇ≈èIóπ");

	WinSock winsock;

	char scan[100];

	for(;;)
	{
		if (scan[0] == '.') break;

		system("cls");
		scanf("%s", &scan);

		if(winsock.Init(scan))
			winsock.ShowIP();

		rewind(stdin);
		getchar();
	}
}