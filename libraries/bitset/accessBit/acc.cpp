

#include <iostream>
#include <bitset>

int main(){
    

    std::bitset<5> bs(18);
    // 1  0  0   1   0
    // 4  3  2   1   0

    std::cout << bs[1] << "\n";
    //std::cout << bs[4] << "\n";
    // returns proxy object(acts like a reference to the bit). You can read or modify it
    
    std::cout << bs.test(1) << "\n";
    //returns the value of the bit(read only)
    

    
    return 0;
}