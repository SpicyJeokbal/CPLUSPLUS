

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")


//CLIENT SIDE
int main(){
    
    WSAData wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(10000);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    int clientSocketConnection = connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if(clientSocketConnection == SOCKET_ERROR){
        std::cerr << "Connection failed. Error: " << WSAGetLastError() << "\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Client to Server connection established\n";

    char buffer[4096];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if(bytesReceived > 0){
        buffer[bytesReceived] = '\0'; //null terminate 
        std::cout << "Server says " << buffer << "\n";
        
        const char *clientReply = "Message received\n";
        send(clientSocket, clientReply, strlen(clientReply), 0);
    }

    closesocket(clientSocket);
    WSACleanup();
    
    return 0;

}