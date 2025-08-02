

#include <iostream>

#pragma once

class Encrypt{
    private:
        std::string privateKey;
    public:
        std::string binaryString;
        std::string input;
        std::string encryptedMessage;

        friend void userInput(Encrypt& encrypt);
        friend void PrivateKeyGenerator(Encrypt& encrypt);
        friend void XOR(Encrypt& encrypt);
        friend void resetCredentials(Encrypt& encrypt);
        
};