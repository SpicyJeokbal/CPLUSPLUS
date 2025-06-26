/* 
#11
Name: Arvin Liel Obayan
Date: 06/26/2025
*/


#include <iostream>
#include <string>


int main(){

    int* ptr = new int;
    *ptr = 15;
    std::cout << *ptr << std::endl;

    delete ptr; //free memory

    return 0;
    
}