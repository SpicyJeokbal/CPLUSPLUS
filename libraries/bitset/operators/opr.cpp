

#include <iostream>
#include <bitset>




/* 

&        Bitwise AND
|        Bitwise OR
^        Bitwise XOR
>>=      Binary right shift and assign
<<=      Binary left shift and assign
&=       Assign the value of bitwise AND to the first bitset
|=       Assign tge value of the bitwise OR to the first bitset
^=       Assign tge value of the bitwise XOR to the first bitset
~        Bitwise NOT

*/


int main(){
    
    std::bitset<8> bs1(18);

    std::bitset<8> bs2(20);

    std::cout << "18: " << bs1 << "\n";
    std::cout << "20: " << bs2 << "\n";

    std::cout << "AND: " << (bs1 & bs2) << "\n";
    std::cout << "OR: " << (bs1 | bs2) << "\n";
    std::cout << "AND: " << (bs1 ^ bs2) << "\n";

    


    
    return 0;
}