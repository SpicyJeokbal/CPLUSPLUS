

#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

/* 
Associates a socket with a local address + port.
Think of it like: “Hey OS, I want this socket to listen on IP X and port Y.”

int bind(
    SOCKET s,                 // socket descriptor
    const struct sockaddr* addr, // pointer to address info
    int namelen               // size of address struct
);

s: your socket from socket().
addr: pointer to a sockaddr_in structure (for IPv4).
namelen: size of that struct (sizeof(sockaddr_in)).

Common struct (sockaddr_in)
struct sockaddr_in serverAddr;
serverAddr.sin_family = AF_INET;                 // IPv4
serverAddr.sin_addr.s_addr = INADDR_ANY;         // any local IP
serverAddr.sin_port = htons(8080);               // port 8080 (host → network byte order)


*/

int main(){
    
    WSADATA wsa;
    int result = WSAStartup(MAKEWORD(2,2), &wsa);

    if(result != 0){
        std::cerr << "WSAStartup failed. Error " << result << "\n";
        return 1;
    }

    std::cout << "Winsock initialized\n";
    std::cout << "Description " << wsa.szDescription << "\n";

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket == INVALID_SOCKET){
        std::cerr << "Socket creation failed. Error: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);

    if(bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR){
        std::cerr << "Bind failed. Error: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    
}