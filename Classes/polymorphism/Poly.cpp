/* 
#21
Name: Arvin Liel Obayan
Date: 07/01/2025
*/


#include <iostream>

class Animal{
    public:
        void animalSound(){
            std::cout << "this animal makes a sound \n";
        }
};

class Pig: public Animal{
    public:
        void animalSound(){
            std::cout<< "This is a pig \n";
        }
};

class Dog: public Animal{
    public:
        void animalSound(){
            std::cout<<"This is a dog \n";
        }
};

class Cat: public Animal{
    public:
        void animalSound(){
            std::cout<<"This is a cat \n";
        }
};



int main(){

    Animal animal;
    Pig pig;
    Dog dog;
    Cat cat;

    animal.animalSound();
    pig.animalSound();
    dog.animalSound();
    cat.animalSound();


    return 0;

}