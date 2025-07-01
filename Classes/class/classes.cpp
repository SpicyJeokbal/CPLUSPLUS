/* 
#13
Name: Arvin Liel Obayan
Date: 06/26/2025
*/


#include <iostream>
#include <string>

class MyClass {
    public:
        int myNum;
        std::string myString;
};


int main(){

    MyClass class1;

    class1.myNum = 1;
    class1.myString = "hello world";

    std::cout << class1.myNum << "\n" << class1.myString << std::endl;

    MyClass class2;

    class2.myNum = 1;
    class2.myString = "hello world";

    std::cout << class2.myNum << "\n" << class2.myString << std::endl;



    return 0;

}