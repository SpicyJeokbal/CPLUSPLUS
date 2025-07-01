/* 
#14
Name: Arvin Liel Obayan
Date: 06/26/2025
*/

#include <iostream>
#include <string>

//inside class definition
class myClass{
    public:
        void myfunction(){
            std::cout << "Hello world" << std::endl; 
        }
};


//outside class definition
class Car{
    public:
        void sound();
};

//this is definition of member
void Car::sound(){
    std::cout << "broom broom";
}



int main(){

    myClass class1;
    Car car;

    std::cout << "Inside class definition" << "\n";
    class1.myfunction();

    std::cout << "Outside class definition" << "\n";
    car.sound();



    return 0;
}