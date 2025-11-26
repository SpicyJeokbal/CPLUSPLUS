
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
SOCKET ftsSocketCreation();
int bindSocket(SOCKET& ftsSocket);
void serverListening(SOCKET& ftsSocket, std::map<std::string, std::vector<char>>& photoLibrary);
void handleClient(SOCKET clientSocket, sockaddr_in clientAddr, std::map<std::string, std::vector<char>>& photoLibrary);
std::vector<char> readFile(const std::string& filename);
void savePhotoBytes(std::map<std::string, std::vector<char>>& photoLibrary);



int main(){
        //   name of photo,   photo in bytes
    std::map<std::string, std::vector<char>> photoLibrary;

    if (!initializedWinsock()) return 1;
    SOCKET ftsSocket = ftsSocketCreation();
    bindSocket(ftsSocket);
    serverListening(ftsSocket, photoLibrary);
    savePhotoBytes(photoLibrary);

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

void serverListening(SOCKET& ftsSocket, std::map<std::string, std::vector<char>>& photoLibrary){
    //accepts multiple clients 
    while(true){
        sockaddr_in clientAddr;
        int clientSize = sizeof(clientAddr);   

        SOCKET clientSocket = accept(ftsSocket, (sockaddr*)&clientAddr, &clientSize);
        if(clientSocket == INVALID_SOCKET){
            std::cerr << "Client socket creation failed. Error: " << WSAGetLastError() << "\n";
            continue;
        }

        
        std::thread clientThread(handleClient, clientSocket, clientAddr, std::ref(photoLibrary));
        clientThread.detach(); // run independently

            if (GetAsyncKeyState(VK_ESCAPE)) break;

    }
    closesocket(ftsSocket);

}

/* WILL CHANGE LATER */
void handleClient(SOCKET clientSocket, sockaddr_in clientAddr, std::map<std::string, std::vector<char>>& photoLibrary){

    try {
        std::cout << "Client connected to thread " << std::this_thread::get_id() << "\n";
        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, INET_ADDRSTRLEN);
        std::cout << "Client connected from " << clientIP << ":" << ntohs(clientAddr.sin_port) << "\n";

        //role checker
        char roleBuffer[32];
        int bytes = recv(clientSocket, roleBuffer, sizeof(roleBuffer), 0);
        if(bytes <= 0) return;
        roleBuffer[bytes] = '\0';
        
        std::string role(roleBuffer);
        if(role.find("ADMIN") != std::string::npos){
            //admin
            std::cout << "Admin connected\n";
            std::string reply = "Hello Admin. You are now connected to the server\n";
            send(clientSocket, reply.c_str(), reply.size(), 0);

            //send list of photos saved in vector, if there's anything else send a message saying "empty photo library"
            int libraryStatus = photoLibrary.empty();
            if(libraryStatus == 1){
                std::string ServerMsg = "Photo library is emptyy\n";
                send(clientSocket, ServerMsg.c_str(), ServerMsg.size(), 0);
                return;
            }
            else{
                std::string libMsg =  "Photo Library contents\n";
                
                for (const auto& item : photoLibrary){
                    libMsg += "Name: " + item.first + " size: " + std::to_string(item.second.size()) + " bytes\n";
                }
                
                send(clientSocket, libMsg.c_str(), libMsg.size(), 0);
            }
            return;
        }
        else{
            //client
            //sendlist of all photos
            std::string list = "Available photos:\n";
            for (const auto& [name, _] : photoLibrary)
                list += "- " + name + "\n";
            list += "\nEnter photo name to Download: ";
            send(clientSocket, list.c_str(), list.size(), 0);

            char buffer[1024];
            int bytesReceived{};

            //wait for clients request
            bytesReceived = recv(clientSocket, buffer, sizeof(buffer) -1, 0);
            if (bytesReceived <= 0){
                std::cout << "Clien disconnected\n";
                closesocket(clientSocket);
                return;
            }

            std::cout << "Client connected\n";
            buffer[bytesReceived] = '\0';
            std::string requestedPhoto = buffer;

            //check if photo exists
            auto it = photoLibrary.find(requestedPhoto);
            if(it == photoLibrary.end()){
                std::string msg = "Photo not found\n";
                send(clientSocket, msg.c_str(), msg.size(), 0);
            }
            else{
                const auto& data = it->second;
                //send file size first
                uint32_t fileSize = data.size();
                send(clientSocket, reinterpret_cast<char*>(&fileSize), sizeof(fileSize), 0);
                //send photo bytes
                send(clientSocket, data.data(), size(data), 0);
                std::cout << "Sent photo: " << requestedPhoto << " (" << fileSize << "bytes)\n";
            }
        }

        
    } catch (const std::exception &e){
        std::cerr << "Error in thread: " << e.what() << "\n";
    }
    closesocket(clientSocket);
    std::cout << "Connection closed on thread " << std::this_thread::get_id() << "\n";
}

//reads photo, turn it into bytes and store it in vector
std::vector<char> readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return {};
    }
    return std::vector<char>((std::istreambuf_iterator<char>(file)), {});
}


void savePhotoBytes(std::map<std::string, std::vector<char>>& photoLibrary){
    int no_of_items {};

    std::cout << "How many photos do you want to add? ";
    std::cin >> no_of_items;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i {0}; i < no_of_items; ++i){
        std::string photoName, filePath;

        std::cout << "\nPhoto " << i << "\n";
        std::cout << "Enter a name for the photo: ";
        std::getline(std::cin, photoName);

        std::cout << "Enter file path: ";
        std::getline(std::cin, filePath);

        //read bytes
        auto photoData = readFile(filePath);

        if(photoData.empty()){
            std::cerr << "Skipping " << photoName << " (couldn't read the file)\n";
            continue;
        }

        //save
        photoLibrary[photoName] = std::move(photoData);
        std::cout << "Added " << photoName << " (" << photoLibrary[photoName].size() << " bytes)\n";

    }
    std::cout << "All photos processed\n";

}




