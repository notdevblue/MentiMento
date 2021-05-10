#include <WS2tcpip.h>
#include <iostream>
#pragma comment(lib, "ws2_32")



int main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2),&wsaData);

	SOCKET sListening;
	// AF_INET	= 192.168.0.1
	// AF_INET6 = 133::ff::::19

	// TCP // SOCK_STREAM
	// UDP // SOCK_DGRAM

	
	sListening = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN serverData;
	serverData.sin_family = AF_INET;
	
	// 56789 번 포트로 가는게 아님
	/*
	
	0x 12 34 56 78

	컴퓨터
	78 56 34 12

	인터넷
	12 34 56 78

	*/
	serverData.sin_port = htons(56789);
	serverData.sin_addr.s_addr = INADDR_ANY;

	bind(sListening, (SOCKADDR*)&serverData, sizeof(serverData));

	listen(sListening, SOMAXCONN);
	
	SOCKADDR_IN clientData;
	int clientDataSize = sizeof(clientData);

	SOCKET sClient = accept(sListening, (SOCKADDR*)&clientData, &clientDataSize);
	std::cout << "connected" << std::endl;

	char chMsg[1024];
	
	recv(sClient, chMsg, 1024, 0);
	std::cout << chMsg << std::endl;
	/*Sleep(100);
	send(sClient, chMsg, 1024, 0);*/
	
	closesocket(sClient);
	closesocket(sListening);

	WSACleanup();

	system("pause");

	return(0);
}