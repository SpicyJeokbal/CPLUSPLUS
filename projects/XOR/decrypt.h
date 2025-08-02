#include <iostream>

#pragma once


class Decrypt{

    private:
        std::string privateKey;
    public:
        std::string binaryString;
        std::string decryptedMessage;

        friend std::string decryptMessage(Decrypt& decrypt);


};

