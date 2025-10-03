

#include <iostream>
#include <winsock2.h>

/* 
listen(serverSocket, SOMAXCONN) - puts the socket into listening mode
serverSocket → the socket you bound.
SOMAXCONN → max number of clients waiting in line (backlog).

accept(serverSocket, (sockaddr*)&clientAddr, &clientSize)

*/

int main(){
    
    WSAData wsa;
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

    listen(serverSocket, SOMAXCONN);

    std::cout << "Server is listening at port 8080...\n";

    sockaddr_in clientAddr;
    int clientSize = sizeof(clientAddr);

    SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);

    if(clientSocket == INVALID_SOCKET){
        std::cerr << "accept failed\n";
    }
    else{
        std::cout << "client connected\n";
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;


    //on another terminal run "telnet 127.0.0.1 portnumber"


}