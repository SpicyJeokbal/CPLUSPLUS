/* 
#9
Name: Arvin Liel Obayan
Date: 06/26/2025
*/


#include <iostream>
#include <string>

int main(){

    //A reference variable is an alias for an existing variable. It is created using the & operator:
    std::string food = "pizza";
    std::string& ref = food;

    //Now, you can use either food or meal to refer to the same value:
    std::cout << food << std::endl;
    std::cout << ref << std::endl;
    std::cout << &food << std::endl;

    return 0;
}