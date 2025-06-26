/* 
#10
Name: Arvin Liel Obayan
Date: 06/26/2025
*/

#include <iostream>
#include <string>

int main(){


    std::string food = "Pizza";

    std::cout << food << std::endl; //outputs the value of food(pizza)
    std::cout << &food << std::endl; //outputs the memory address

    std::string* ptr = &food; //pointer declaration
    std::cout << ptr << std::endl; // This is called Reference. Output the memory address of food with the pointer
    std::cout << *ptr << std::endl; // This is called Dereference. outputs the value at the address

    //change the value of the pointer
    *ptr = "Hamburger";

    
    std::cout << food << std::endl;
    std::cout << *ptr << std::endl;

    





    return 0;
}