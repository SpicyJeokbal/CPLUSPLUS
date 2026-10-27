#include <iostream>

//===========Constructor Overloading===========

/* 
- constructor overloading means having multiple constructor in the same class,
each accepting different parameters.
*/

/* 
- Constructors must have different parameters. These constructor differ by
the number of parameters. You can also overload by parameter types.
Even different parameter orders is accepted

- Changing only parameter names doest count
`class Box {
public:
    Box(int x) {}
    Box(int size) {} // Error: same parameter type
};
`
Both constructors only accept one int. C++ doesnt use parameter names
to distinguish overloaded functions

- Constructors dont have return type, so you cannot overload by changing 
a return type

- you can combine overloaded constructors with initializers list

*/

class _ab{
public:
    int size{};
    int x{};
    int y{};
    int z{};
    std::string name = "_memo_1";



    _ab(int _x_axis, int _y_axis, int _z_axis);

    /* 
    From the compilers perspective the two constructors below are the same.
    */

    //_ab(){}
    _ab(): size(256), x(10), y(10), z(10), name("_memo_2"){}

    _ab(int memory, int i, int j, int k, std::string _name);

};

_ab::_ab(int _x_axis, int _y_axis, int _z_axis){
    this ->x = _x_axis;
    this ->y = _y_axis;
    this ->z = _z_axis;
}

_ab::_ab(int memory, int i, int j, int k, std::string _name): size(memory), x(i), y(j), z(k), name(_name) {}

class _ac{
public:
    int _x{};
    int _y{};
    int _z{};

    _ac(): _x(20), _y(21), _z(22){}

    _ac(int i, int j, int k): _x(i), _y(j), _z(k){}
};

int main(){
    
    _ab ab;
    std::cout << ab.size << " " << ab.x << " " << ab.y << " " << ab.z << " " << ab.name << " " << std::endl;

    _ab _a_b(10, 11, 12);
    std::cout << _a_b.x << " " << _a_b.y << " " << _a_b.z << std::endl;

    _ab ab_;
    std::cout << ab_.x << " " << ab_.y << " " << ab_.z << ab_.name << " " << std::endl;

    _ab _ab_(256, 40, 50, 60, "memo_3");
    std::cout << _ab_.size << " " << _ab_.x << " " << _ab_.y << " " << _ab_.z << " " << _ab_.name << std::endl;

    _ac ac;
    std::cout << ac._x << " " << ac._y << " " << ac._z << std::endl;

    _ac ac_(30,31,32);
    std::cout << ac_._x << " " << ac_._y << " " << ac_._z << std::endl;

    return 0;
}