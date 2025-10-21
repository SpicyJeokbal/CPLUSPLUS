

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")


int main(){

    WSADATA wsa;
    WSAStartup (MAKEWORD(2,2), &wsa);

    //create client socket
    SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8053);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    unsigned char query[] = { 
        0x03,'w','w','w',
        0x06,'g','o','o','g','l','e',
        0x03,'c','o','m',
        0x00
    };

     
    sendto(clientSocket, reinterpret_cast<const char*>(query), sizeof(query), 0, (sockaddr*)&serverAddr, sizeof(serverAddr));

    char buffer[512];
    sockaddr_in fromAddr;
    int fromLen = sizeof(fromAddr);
    int recvLen = recvfrom(clientSocket, buffer, sizeof(buffer), 0, (sockaddr*)&fromAddr, &fromLen);

    if(recvLen > 0){
        std::cout << "Got " <<recvLen << " bytes from DNS Server\n";
    }

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}