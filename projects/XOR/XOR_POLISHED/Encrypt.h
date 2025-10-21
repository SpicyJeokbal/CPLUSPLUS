
#pragma once
#include <bitset>
#include <iostream>
#include <random>



class Encryptor{
    public:

        std::bitset<8> encryptText(char c){
            std::bitset<8> binary(c);
            std::bitset<8> key = std::bitset<8>(dist(gen));  //creates new key everytime encryptText gets called
            return binary ^ key;
        }


    private:
        std::random_device rd;
        std::mt19937 gen{rd()};
        std::uniform_int_distribution<> dist{0,255};
};