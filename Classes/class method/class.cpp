/* 
#14
Name: Arvin Liel Obayan
Date: 06/26/2025
*/

#include <iostream>
#include <string>

/* 
inside class definition
you define the function directly inside the class
pros:
- easier to read for small classes
- good for simple functions
- less code to write
*/
class myClass{
    public:
        void myfunction(){
            std::cout << "Hello world" << std::endl; 
        }
};


/*  
outside class definition
inside the class you only declare the function
*/
class Car{
    public:
        void sound();
};

/*
define the function outside of the class using Scope Resolution operator `::`

`Car::` means that sound() function belongs to Car class

*/
void Car::sound(){
    std::cout << "broom broom";
}

//Why use outside function to begin with
//Imagine this:
class Player {
public:
    void move(){/* 50 lines of code */}
    void attack(){/* 100 lines of code */}
    void heal(){/* 50 lines of code */}
    //the class becomes too huge and hard to read
};

//instead
class Player {
public:
    void move();
    void attack();
    void heal();
};

void Player::move(){
    //code
}
void Player::attack(){
    //code
}
void Player::heal(){
    //code
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