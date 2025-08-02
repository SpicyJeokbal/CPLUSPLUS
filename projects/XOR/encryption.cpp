
//XOR

#include <iostream>
#include <bitset>
#include <cstdlib>
#include <random>
#include <ctime>
#include <fstream>
#include "encrypt.h"
#include "decrypt.h"





void userInput(Encrypt& encrypt){

    std::cout << "Enter a word: ";
    std::cin >> encrypt.input;

    for(char c : encrypt.input){
        encrypt.binaryString += std::bitset<8>(c).to_string();
    }

    std::cout << "Binary version: " << encrypt.binaryString << "\n";
}

void PrivateKeyGenerator(Encrypt& encrypt) {
    int key_length = encrypt.binaryString.length();

    std::srand(std::time(nullptr)); // seed once

    std::string generatedKey;

    for (int i = 0; i < key_length; i++) {
        int randomBit = std::rand() % 2;
        generatedKey += (randomBit == 1) ? '1' : '0';
    }

    encrypt.privateKey = generatedKey;

    std::ofstream writePrivateKey("Private_Key.txt");

    writePrivateKey << encrypt.privateKey;

    writePrivateKey.close();

    //std::cout << "Private key: " << encrypt.privateKey << "\n";
}

void XOR(Encrypt& encrypt){

    int key_length = encrypt.binaryString.length();
    
    for(int i = 0; i < key_length; i++){
        encrypt.encryptedMessage += (encrypt.binaryString[i] == encrypt.privateKey[i]) ? '0' : '1'; 
    }

    std::cout << "Encrypted message: " << encrypt.encryptedMessage << "\n";

}

void resetCredentials(Encrypt& encrypt){
    encrypt.binaryString.clear();
    encrypt.privateKey.clear();
    encrypt.encryptedMessage.clear();
}



std::string decryptMessage(Decrypt& decrypt){

    std::cout << "Enter Encrypted message: ";
    std::cin >> decrypt.decryptedMessage;

    std::ifstream ReadPrivateKey("Private_Key.txt");
    if(ReadPrivateKey.is_open()){
        std::string line;
        while(std::getline(ReadPrivateKey, line)){
            //std:: cout << line;
            decrypt.privateKey = line;
        }
        ReadPrivateKey.close();
    } else {
        std::cout << "file not found";
        return 0;
    }

    std::string binaryResult = "";
    int key_length = decrypt.privateKey.length();

    for (int i = 0; i < key_length && i < decrypt.decryptedMessage.length(); i++) {
        binaryResult += (decrypt.decryptedMessage[i] == decrypt.privateKey[i]) ? '0' : '1';
    }

    std::string text = "";
    for (size_t i = 0; i + 7 < binaryResult.length(); i += 8) {
        std::string byte = binaryResult.substr(i, 8);
        char character = static_cast<char>(std::bitset<8>(byte).to_ulong());
        text += character;
    }

    std::cout << "Decrypted message: " << text << "\n";
    return text;

}








int main(){ 
    
    

    Encrypt encrypt;
    Decrypt decrypt;
    resetCredentials(encrypt);

    while(true){

        int choice;
        std::cout << "1.Encrypt message \n2.Decrypt message \n3.Exit\n";
        std::cin >> choice;

        switch(choice){

            case 1:
                userInput(encrypt);
                PrivateKeyGenerator(encrypt);
                XOR(encrypt);
                break;
            case 2:
                decryptMessage(decrypt);
                break;
            case 3:
                std::cout << "bye\n"; 
                break;
            default:
                std::cout << "bye\n"; 
                break;
        }

    }
}