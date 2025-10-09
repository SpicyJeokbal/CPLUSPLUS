

#include <iostream>
#include <bitset>

int main(){
    
    std::bitset<5> bs(18);
    //size 5 bits and stores value 18 in binary form
    //can also be initialize using the binary version. However, it is more error prone so initializing it as an interger is more preferred.
    //std::bit<5> bs("10010");

    std::cout << bs;


    return 0;
}