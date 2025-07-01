/* 
#18
Name: Arvin Liel Obayan
Date: 06/26/2025
*/

#include <iostream>
#include <string>

/* 
Inheritance allows one class to reuse attributes and methods from another class. It helps you write cleaner, more efficient code by avoiding duplication.
We group the "inheritance concept" into two categories:
derived class (child) - the class that inherits from another class
base class (parent) - the class being inherited from
To inherit from a class, use the : symbol.
*/

/* 
Why And When To Use "Inheritance"?
- It is useful for code reusability: reuse attributes and methods of an existing class when you create a new class.

*/


//base class
class vehicle{
    public:
        std::string brand = "Ford";

        void sound(){
            std::cout << "broom broom" << std::endl;
        }
};

//derived class
class Car: public vehicle{
    public:
        std::string model = "Mustang";

};

int main(){

    Car car;
    car.sound();
    std::cout << car.brand << " " << car.model;



    return 0;

}