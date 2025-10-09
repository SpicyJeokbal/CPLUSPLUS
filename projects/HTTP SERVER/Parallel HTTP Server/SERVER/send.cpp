
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
#pragma comment(lib, "ws2_32.lib")


void handleClient(SOCKET clientSocket){
    std::cout << "Client connected to " << std::this_thread::get_id() << "\n";

    const char *msg = "You are now connected to the server side...";
    int byteSent = send(clientSocket, msg, strlen(msg), 0);
    if(byteSent == SOCKET_ERROR){
        std::cerr << "Send failed. Error: " << WSAGetLastError() << "\n";
    }

    closesocket(clientSocket);
    std::cout << "Client disconnected from thread " << std::this_thread::get_id() << "\n";

}



//SERVER SIDE
int main(){
    
    WSAData wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    std::cout << "Winsock initialized\n";
    std::cout << "Description " << wsa.szDescription << "\n";

    
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

    std::cout << "Server is listening at port 10000\n"; 

    //accepts multiple clients 
    while(true){
        sockaddr_in clientAddr;
        int clientSize = sizeof(clientAddr);   

        SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
        if(clientSocket == INVALID_SOCKET){
            std::cerr << "Client socket creation failed. Error: " << WSAGetLastError() << "\n";
            continue;
        }

        
        std::thread clientThread(handleClient, clientSocket);
        clientThread.detach(); // run independently

        
    }
    closesocket(serverSocket);
    WSACleanup();

    return 0;

    
}