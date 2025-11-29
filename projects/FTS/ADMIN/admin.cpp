

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
#include <map>
#include <vector>
#include <fstream>
#include <limits>
#pragma comment(lib, "ws2_32.lib")


bool initializedWinsock();
SOCKET createAdminSocket();
void handleServer(SOCKET& adminSocket);


int main(){
    
    if (!initializedWinsock()) return 1;

    SOCKET adminSocket = createAdminSocket();
    if(adminSocket == INVALID_SOCKET) return 1;

    handleServer(adminSocket);
    
    
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

SOCKET createAdminSocket(){
    SOCKET adminSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(adminSocket == INVALID_SOCKET){
        std::cerr << "Client socket creation failed. Error: " << WSAGetLastError << "\n";
        WSACleanup();
        return INVALID_SOCKET;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(10000);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    int clientSocketConnection = connect(adminSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if(clientSocketConnection == SOCKET_ERROR){
        std::cerr << "Connection failed. Error: " << WSAGetLastError() << "\n";
        closesocket(adminSocket);
        WSACleanup();
        return INVALID_SOCKET;
    }

    std::cout << "Client to Server connection established\n";
    return adminSocket;
}

void handleServer(SOCKET& adminSocket){

    //send role
    const char* role = "ADMIN";
    send(adminSocket, role, strlen(role), 0);

    char buffer[4096];

    while(true) {
        int bytesReceived = recv(adminSocket, buffer, sizeof(buffer) - 1, 0);
        
        if (bytesReceived <= 0){
            std::cout << "Server disconnected\n";
            break;
        }

        buffer[bytesReceived] = '\0';
        std::cout << buffer << "\n";

        if(strstr(buffer, "Choose your option")){

            std::string choice;
            std::cout << "Your choice: ";
            std::getline(std::cin, choice);

            send(adminSocket, choice.c_str(), choice.size(), 0);
        }
    }
    closesocket(adminSocket);
}
