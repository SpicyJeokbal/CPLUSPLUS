#include <bits/stdc++.h>
#include <bitset>


std::string StringToBinary(const std::string& text, std::string binary){

    for(char c : text){
        binary += std::bitset<8>(c).to_string();
    }

    std::cout << binary << "\n";

    return binary;

}


std::string BinaryToString(const std::string& binary, std::string text){

    for(size_t i = 0; i < binary.length();i++){
        std::bitset<8> bits(binary.substr(i,8));
        text += char(bits.to_ulong());  //converts binary value to an unsigned long, "01101000" → 104
    }

    std::cout << text;
    return text;

}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string binary;
    std::string text = "hello";

    StringToBinary(text, binary);
    BinaryToString(binary, text);
    
}