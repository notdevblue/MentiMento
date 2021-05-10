#include <WS2tcpip.h>
#include <iostream>
#pragma comment(lib, "ws2_32")



int main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET sListening;
	// AF_INET	= 192.168.0.1
	// AF_INET6 = 133::ff::::19

	// TCP // SOCK_STREAM
	// UDP // SOCK_DGRAM


	sListening = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN serverData;
	serverData.sin_family = AF_INET;

	serverData.sin_port = htons(56789);
	InetPton(AF_INET, TEXT("127.0.0.1"), &serverData.sin_addr);

	connect(sListening, (SOCKADDR*)&serverData, sizeof(serverData));


	char chMsg[1024] = { "¿Í¼¾Áê" };
	Sleep(200);
	send(sListening, chMsg, 1024, 0);
	
	closesocket(sListening);

	WSACleanup();
	system("pause");
	return(0);
}