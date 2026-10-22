/* 
#100
Name: Liyel
Date: 10/22/2026
*/

#include <iostream>

/* 
The three variables below have different lifespan

*/


//exist from start until the program ends. Global variables have static duration automatically.
//Meaning the allocation happens before main() is starts
//stored in the data segment
int _global_number{10};

int main(){
    /* 

    exist for the entire program even tho its declared inside main()
    stored in the data segment

    When should u use static?
    - if you want the variable to be remembered all throughout program
    - when you want a value shared across all calls
    - class variables shared by all objects
     */
    static int count{5};
    
    //normally exist when the block or function is executing
    //stored in stack
    int age{5}; 

    // *ptr is stored in heap
    // ptr is stored in stack
    int* ptr = new int(10);
    
    std::cout << _global_number << std::endl;
    std::cout << count << std::endl;
    std::cout << age << std::endl;
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;

    return 0;
}