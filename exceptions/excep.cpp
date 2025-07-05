/* 
#25
Name: Arvin Liel Obayan
Date: 07/05/2025
*/


#include <iostream>

int main(){


    try {
        int age = 15;
        if (age >= 18) {
            std::cout << "Access granted - you are old enough.";
        } else {
            throw (age);
        }
    }
    catch (int myNum) {
        std::cout << "Access denied - You must be at least 18 years old.\n";
        std::cout << "Age is: " << myNum;
    }


    return 0;
}

