

#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

std::string parseDomainName(unsigned char* buffer, int& start);


int main(){
    
    WSAData wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);
    

    //create udp socket
    SOCKET dnsServerSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if(dnsServerSocket == INVALID_SOCKET){
        std::cerr << "Socket creation failed. Error: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }
    else{
        std::cout << "DNS Socket creation success!!\n";
    }

    //bind to a port
    sockaddr_in dnsServerAddr;
    dnsServerAddr.sin_family = AF_INET;
    dnsServerAddr.sin_addr.s_addr = INADDR_ANY;
    dnsServerAddr.sin_port = htons(8053);

    if(bind(dnsServerSocket, (sockaddr*)&dnsServerAddr, sizeof(dnsServerAddr)) == SOCKET_ERROR){
        std::cerr << "Bind failed. Error: " << WSAGetLastError() << "\n";
        closesocket(dnsServerSocket);
        closesocket(dnsServerSocket);
        WSACleanup();
        return 1;
    }
    


    //put server to listen mode
    //dns server uses udp
    while(true){
        sockaddr_in clientAddr;
        int clientSize = sizeof(clientAddr);
        char buffer[512];   
        char response[512];   


        int recvLen = recvfrom(dnsServerSocket, buffer, sizeof(buffer), 0, (sockaddr*)&clientAddr, &clientSize);
        if(recvLen == SOCKET_ERROR){
            std::cerr << "recvfrom failed\n";
            continue;  
        }
        
        int start{0};
        std::string domain = parseDomainName(reinterpret_cast<unsigned char *>(buffer), start);
        std::cout << "query ready for " << domain << "\n";

        //build a DNS packet response into 'response'

        sendto(dnsServerSocket, response, sizeof(response), 0, (sockaddr*)&clientAddr, clientSize);

    }

    closesocket(dnsServerSocket);
    WSACleanup();

    return 0;
}



/* 
03                77      77    77     06              67     6f       6f    67 6c 65 03 63 6f 6d 00
length of         w       w     w      length of 
the next label                         the next label
(3 chars)                              (6 chars)
*/
std::string parseDomainName(unsigned char* buffer, int& start){
    std::string domain;
    int pos = start;

    while(buffer[pos] != 0){
        int len = buffer[pos];
        pos++;

        for(int i = 0; i <len; i++){
            domain+= buffer[pos + i];
        }

        pos += len;
        domain += '.';

    }

    if(!domain.empty()) domain.pop_back();

    return domain;
}
