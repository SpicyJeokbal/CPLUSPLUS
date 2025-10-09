
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")


//SERVER SIDE. SENDER
/* 
int send(
    SOCKET s,          // the socket you're sending on
    const char *buf,   // pointer to your message/data
    int len,           // length of the data in bytes
    int flags          // usually 0
);

*/

//SERVER SIDE
int main(){
    
    WSAData wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    std::cout << "Winsock initialized\n";
    std::cout << "Description " << wsa.szDescription << "\n";

    //client socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    
    if(serverSocket == INVALID_SOCKET){
        std::cerr << "Server socket creation failed. Error: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(10000);


    if(bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR){
        std::cerr << "Socket binding failed. Error: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    listen(serverSocket, SOMAXCONN);

    std::cout << "Server is listening at port 10000"; 

    //accepts multiple clients sequentially
    while(true){
        sockaddr_in clientAddr;
        int clientSize = sizeof(clientAddr);   

        SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
        if(clientSocket == INVALID_SOCKET){
            std::cerr << "Client socket creation failed. Error: " << WSAGetLastError() << "\n";
            continue;
        }

        std::cout << "Client connected \n";

        const char *msg = "You are now connected to the server side...";
        int byteSent = send(clientSocket, msg, strlen(msg), 0);
        if(byteSent == SOCKET_ERROR){
            std::cerr << "Send failed. Error: " << WSAGetLastError() << "\n";
        }


        closesocket(clientSocket);
        std::cout << "Client connected\n";
    }
    closesocket(serverSocket);
    WSACleanup();

    return 0;

}