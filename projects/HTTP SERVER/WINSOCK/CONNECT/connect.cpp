
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

/* 
What connect() Does
    connect() is used on the client side.
    opposite of accept
        Server: socket() → bind() → listen() → accept()
        Client: socket() → connect()
    Its job: ask the operating system to establish a TCP connection (or UDP association) to a server socket.
    It sends a SYN packet (for TCP), and if the server replies with SYN-ACK, then your client replies with ACK → now you have a connection (the TCP 3-way handshake).

int connect(
    SOCKET s,
    const struct sockaddr* name,
    int namelen
);

s → the client’s socket (created with socket()).
addr → the server’s sockaddr_in (cast to sockaddr*).
addrlen → size of that struct.

Returns:
0 = success
SOCKET_ERROR = failure (use WSAGetLastError() to see why)



int inet_pton(
    int af,           // address family (AF_INET for IPv4, AF_INET6 for IPv6)
    const char *src,  // IP address in string form ("127.0.0.1")
    void *dst         // pointer to where binary form will be stored
);

af → AF_INET (IPv4) or AF_INET6 (IPv6).
src → your IP string ("192.168.1.10").
dst → usually &serverAddr.sin_addr.







*/




int main(){
    
    WSAData wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    std::cout << "Winsock initialized\n";
    std::cout << "Description " << wsa.szDescription << "\n";

    //client socket
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); //server IP

    //connect to the server
    int result = connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if(result == SOCKET_ERROR){
        std::cerr << "Connection failed. Error: " << WSAGetLastError() << "\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to the server...\n";

    WSACleanup();

    return 0;

}