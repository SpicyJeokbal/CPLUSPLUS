/* 
#10
Name: Arvin Liel Obayan
Date: 06/26/2025
*/

#include <iostream>
#include <string>

struct _box{
    int number;
};


int main(){


    std::string food = "Pizza";

    std::cout << food << std::endl; //outputs the value of food(pizza)
    std::cout << &food << std::endl; //outputs the memory address

    std::string* ptr = &food; //pointer declaration expects an address stored in pointer
    std::cout << ptr << std::endl; // This is called Reference. Output the memory address of food with the pointer
    std::cout << *ptr << std::endl; // This is called Dereference. outputs the value at the address

    _box b;
    b.number = 11;

    _box* p = &b;
    //dereference but for objects
    std::cout << p->number << std::endl;

    //change the value of the pointer
    /* 

    You have to use assignment and not initialization cause the variable has already been created.
    *ptr("Hamburger"); wont wont work

    */
    *ptr = "Hamburger";

    
    std::cout << food << std::endl;
    std::cout << *ptr << std::endl;


    return 0;
}