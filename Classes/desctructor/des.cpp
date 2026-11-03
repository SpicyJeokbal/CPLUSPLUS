
#include <iostream>

//=============DESTRUCTOR=============
/* 
Prefixed with `~`. Automatically called when the object goes out of scope or
is destroyed to free resources.

It doesnt require a parameter or a return value.

Cannot be declared as static or const-qualified because a destructor is meant to
destroy the object, inherently modifying its state.

A class can only have one destructor and cannot be overloaded.

Destructor release resources and destroys objects in reverse order of creation.

By default, the compiler will provide a destructor to a class if there's none.

The default destructor works fine with for classes without dynamic memory or pointers

If a class has a pointer or dynamic allocated memory, u must write a destructor



*/



class _ab{
private:
    int* _x{};    
    int* _y{};    
    int* _z{};    

public:
    void _setData(int _i){
        _x = new int(_i);
    }
    
    int _getData(){
        if(_x != nullptr){return *_x;}
        return 0;
    }

    ~_ab(){
        delete _x;
    }

};


int main(){
    
    _ab ab;
    
    std::cout << ab._getData() << std::endl;

    ab._setData(10);

    std::cout << ab._getData() << std::endl;

    return 0;
}