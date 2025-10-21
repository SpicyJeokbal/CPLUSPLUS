

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")


bool initializedWinsock();
SOCKET createClientSocket();
void handleServer(SOCKET& clientSocket);


//CLIENT SIDE
int main(){
    
    if (!initializedWinsock()) return 1;

    SOCKET clientSocket = createClientSocket();
    if(clientSocket == INVALID_SOCKET) return 1;

    handleServer(clientSocket);
    
    
    return 0;

}

bool initializedWinsock(){
    WSAData wsa;
    int result = WSAStartup(MAKEWORD(2,2), &wsa);

    if (result != 0){
        std::cerr << "WSAStartup failed! Error code: " << result << "\n";
        return false;
    }

    std::cout << "Winsock initialized\n";
    std::cout << "Description " << wsa.szDescription << "\n";
    return true;

}

SOCKET createClientSocket(){
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket == INVALID_SOCKET){
        std::cerr << "Client socket creation failed. Error: " << WSAGetLastError << "\n";
        WSACleanup();
        return INVALID_SOCKET;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(10000);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    int clientSocketConnection = connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if(clientSocketConnection == SOCKET_ERROR){
        std::cerr << "Connection failed. Error: " << WSAGetLastError() << "\n";
        closesocket(clientSocket);
        WSACleanup();
        return INVALID_SOCKET;
    }

    std::cout << "Client to Server connection established\n";
    return clientSocket;
}

void handleServer(SOCKET& clientSocket){
    char buffer[4096];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if(bytesReceived > 0){
        buffer[bytesReceived] = '\0'; //null terminate 
        std::cout << "Request:\n" << buffer << "\n";
        
        const char *clientReply = "Message received\n";
        send(clientSocket, clientReply, strlen(clientReply), 0);
    }

    closesocket(clientSocket);
    WSACleanup();
}
