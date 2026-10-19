/* 
#8
Name: Arvin Liel Obayan
Date: 06/26/2025
*/


#include <iostream>
#include <string>

/* 
Why And When To Use Enums?

Enums are used to give names to constants, which makes the code easier to read and maintain.
Use enums when you have values that you know aren't going to change, like month days, days, colors, deck of cards, etc.
*/


//Note that if you assign a value to one specific item, the next items will update their numbers accordingly:
enum Level {
    LOW = 1,
    MEDIUM /* now 2 */,
    HIGH //now 3
};

enum class Fruit { Apple = 1, Banana, Cherry};


int main(){

    //An enum is a special type that represents a group of constants (unchangeable values).
    /* enum Level myVar = MEDIUM;

    switch(myVar){
        case 1:
            std::cout << "Low";
            break;
        case 2:
            std::cout << "Medium";
            break;
        case 3:
            std::cout << "High";
            break;
    } */

    //iterate through an Enum


    /* //1. use the underlying integer values
    for(int i = LOW; i <= HIGH; ++i){
        std::cout << i << "\n";
    }

    //2. Store the enum in an array

    Level lvl[] = {LOW, MEDIUM, HIGH};

    for(Level lvl : lvl){
        std::cout << lvl << "\n";
    } */

    //3. use enum class with arrays
    Fruit fruits[] = {Fruit::Apple, Fruit::Banana, Fruit::Cherry};

    for(auto f : fruits){
        std::cout << static_cast<int>(f)<< "\n";
    }


    return 0;
}