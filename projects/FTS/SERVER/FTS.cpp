
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
#pragma comment(lib, "ws2_32.lib")

bool initializedWinsock();
SOCKET ftsSocket();
int bindSocket(SOCKET& ftsSocket);
void serverListening(SOCKET& ftsSocket);
void handleClient(SOCKET clientSocket, sockaddr_in clientAddr);

int main(){
    
    if (!initializedWinsock()) return 1;
    SOCKET ftsSocket = ftsSocketCreation();
    bindSocket(ftsSocket);

    return 0;
}

/* ====================================================================================  */

bool initializedWinsock(){
    WSAData wsa;
    int winsockResult = WSAStartup(MAKEWORD(2,2), &wsa);

    if(winsockResult != 0){
        std::cerr << "Winsock2 failed to initialized. Error: " << winsockResult << "\n";
        return false;
    }

    std::cout << "Winsock2 initialized" << "\n";
    std::cout << "Description:" << wsa.szDescription << "\n";

    return true;
}

SOCKET ftsSocketCreation(){
    SOCKET ftsSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (ftsSocket != INVALID_SOCKET) return ftsSocket;

    std::cerr << "Server socket creation failed. Error: " << WSAGetLastError() << "\n";
    closesocket(ftsSocket);
    WSACleanup();
    return INVALID_SOCKET;
}

int bindSocket(SOCKET& ftsSocket){
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(10000);

    int opt {1};
    setsockopt(ftsSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));

    if(bind(ftsSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR){
        std::cerr << "Socket binding failed. Error: " << WSAGetLastError() << "\n";
        closesocket(ftsSocket);
        WSACleanup();
        return 1;
    }

    listen(ftsSocket, SOMAXCONN);

    std::cout << "Server is listening at port 10000\n"; 

    return 0;
}

void serverListening(SOCKET& ftsSocket){
    //accepts multiple clients 
    while(true){
        sockaddr_in clientAddr;
        int clientSize = sizeof(clientAddr);   

        SOCKET clientSocket = accept(ftsSocket, (sockaddr*)&clientAddr, &clientSize);
        if(clientSocket == INVALID_SOCKET){
            std::cerr << "Client socket creation failed. Error: " << WSAGetLastError() << "\n";
            continue;
        }

        
        std::thread clientThread(handleClient, clientSocket, clientAddr);
        clientThread.detach(); // run independently

            if (GetAsyncKeyState(VK_ESCAPE)) break;

    }
    closesocket(ftsSocket);
    WSACleanup();
}

/* WILL CHANGE LATER */
void handleClient(SOCKET clientSocket, sockaddr_in clientAddr){

    try {
        std::cout << "Client connected to thread " << std::this_thread::get_id() << "\n";
        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, INET_ADDRSTRLEN);
        std::cout << "Client connected from " << clientIP << ":" << ntohs(clientAddr.sin_port) << "\n";


        const char *httpResponse =  "HTTP/1.1 200 OK\r\n"
                                    "Content-Type: text/plain\r\n"
                                    "Content-Length: 37\r\n"
                                    "Connection: close\r\n"
                                    "\r\n"
                                    "You are now connected to the server side...";
        int byteSent = send(clientSocket, httpResponse, strlen(httpResponse), 0);
        if(byteSent == SOCKET_ERROR){
            std::cerr << "Send failed. Error: " << WSAGetLastError() << "\n";
        }

        std::cout << "Client disconnected from thread " << std::this_thread::get_id() << "\n";
    } catch (const std::exception &e){
        std::cerr << "Error in thread: " << e.what() << "\n";
    }
    closesocket(clientSocket);

}


