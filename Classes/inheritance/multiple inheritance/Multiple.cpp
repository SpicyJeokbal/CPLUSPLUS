/* 
#20
Name: Arvin Liel Obayan
Date: 07/01/2025
*/

#include <iostream>

class MyClass{
    public:
        void MyFunction(){
            std::cout << "Parent A";
        }
};

class AnotherClass{
    public:
        void OtherFunction(){
            std::cout << "Parent B";
        }
};


class Child: public MyClass, public AnotherClass{

};


int main(){

    Child c1;
    c1.MyFunction();
    std::cout<< std::endl;
    c1.OtherFunction();



    return 0;
}