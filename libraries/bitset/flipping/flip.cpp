

#include <iostream>
#include <bitset>

/* 
Setting means making the bit at particular position 1 and resetting means making it 0. 
These operations can be done using set() and reset() function. The flip() function can 
be used to set the bit if it's not set and unset if it is set.
*/


int main(){
    
    std::bitset<8> bs(18);

    std::cout << bs << "\n";
    //00010010
    /* bs.reset(1);
    std::cout << "After resetting: " << bs << "\n";
    bs.set(0);
    std::cout << "After setting: " << bs << "\n"; */
    bs.flip();
    std::cout << "After flipping: " << bs << "\n";

    



    return 0;
}