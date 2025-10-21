

#include <iostream>
#include <bitset>
#include <random>
#include "Encrypt.h"


void encryptMessage(std::string& text, Encryptor& en);



int main(){
    
    Encryptor en;

    std::string text = "Hello world";

    encryptMessage(text, en); 
    
    std::cout << "\n";

    return 0;
}

void encryptMessage(std::string& text, Encryptor& en){
    for(char c : text){
        std::bitset<8> encryptedMessage = en.encryptText(c);
        std::cout << encryptedMessage;
    }
}
