
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")


/* 
create a new socket
SOCKET socket(
    int af,       // address family (IPv4, IPv6, etc.)
    int type,     // socket type (stream or datagram)
    int protocol  // protocol (TCP, UDP, or 0 = auto)
);
Parameters
af (Address Family):
    AF_INET → IPv4
    AF_INET6 → IPv6

type:
    SOCK_STREAM → TCP (reliable, connection-based)
    SOCK_DGRAM → UDP (fast, connectionless)

protocol:
    Usually 0 (system picks correct protocol).
    Or explicitly IPPROTO_TCP / IPPROTO_UDP.

Return value
    Returns a socket descriptor (SOCKET type, on Windows).
    Returns INVALID_SOCKET (-1) if failed → check with WSAGetLastError().

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
    else{
        std::cout << "Socket creation success!!\n";
    }




    WSACleanup();

    return 0;
    
}