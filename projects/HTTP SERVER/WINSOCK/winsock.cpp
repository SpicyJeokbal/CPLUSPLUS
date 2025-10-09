


#include <iostream>
#include <WinSock2.h>
// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

int main(){

    /* int WSAStartup(   //MUST CALL BEFORE ANY OTHER WINSOCK FUNCTION
        WORD wVersionRequested,  // version you want
        LPWSADATA lpWSAData      // pointer to structure with details
    ); 
    
    typedef struct WSAData {
        WORD           wVersion;      // version of Winsock you got
        WORD           wHighVersion;  // highest supported version
        char           szDescription[WSADESCRIPTION_LEN+1]; 
        char           szSystemStatus[WSASYSSTATUS_LEN+1];
        unsigned short iMaxSockets;
        unsigned short iMaxUdpDg;
        char FAR *     lpVendorInfo;
    } WSADATA, *LPWSADATA;

    SOCKET socket(
        int af,       // address family (IPv4, IPv6, etc.)
        int type,     // socket type (stream or datagram)
        int protocol  // protocol (TCP, UDP, or 0 = auto)
    );


    
    */

    WSADATA wsa;
    //allocates resources for winsock
    int result = WSAStartup(MAKEWORD(2,2), &wsa);  //requests winsock v 2.2, &wsa - contain infomation about winsock implementation

    if(result != 0){
        std::cerr << "WSAStartup failed. Error " << result << "\n";
        return 1;
    }

    std::cout << "Winsock initialized\n";
    std::cout << "Description " << wsa.szDescription << "\n";





    //free allocated winsock resources
    WSACleanup();

    return 0;
}