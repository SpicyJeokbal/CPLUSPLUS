/* 
#26
Name: Arvin Liel Obayan
Date: 10/07/2025
*/

#include <iostream>


int main(){

    int number;
    std::cout << "enter a number: ";
    while(!(std::cin >> number)){
        std::cout << "invalid number!" << std::endl;
        std::cin.clear();//reset input errors
        std::cin.ignore(1000, '\n'); // remove bad input
    }

    std::cout << number << std::endl;

    std::string name;
    do{
        std::cout << "enter your name: ";
        std::getline(std::cin, name);
    }while(name.empty());
    std::cout << name << std::endl;

    return 0;
}