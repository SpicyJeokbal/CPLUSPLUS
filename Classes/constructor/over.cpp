#include <iostream>

//===========Initialize value without parameters===========


/* 
This is an example of directly assigning values inside the constructors body
_alloc(){
    size = 256;
    x = 10;
    y = 11;
    z = 12;
}
/*

/*
==========================================================
1. Member Initializer list
- Same results as directly assigning values, but technically,
the values are initialized directly instead of being assigned
values inside the constructor's body
- use this when there's const members and references
*/
class _ab{
public:
    int size{};
    int x{};
    int y{};
    int z{};

    _ab(): size(256), x(10), y(11), z(12){

    }

};

/*
==========================================================
2. Default member initializers
- directyly assign values where you declare the variables
- now, whenever you create a _ac object, those members receive
their default values automatically.
- use this when setting constructor values across constructors
*/

class _ac{
public:
    int size{};
    int x{};
    int y{};
    int z{};
    std::string name = "_memo_1";

    _ac(){}

};

int main(){

    _ab ab;
    _ac ac;

    //Member initializer list
    std::cout << ab.size << " " << ab.x << " " << ab.y << " " << ab.z << std::endl;
    //Default member initializer
    std::cout << ac.size << " " << ac.x << " " << ac.y << " " << ac.z << " " << ac.name << std::endl;
    
    
    return 0;
}