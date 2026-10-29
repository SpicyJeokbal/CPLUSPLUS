#include <iostream>

/* 
Struct and Class are almost the same thing in C++. The main difference is that
struct members are public by default, and class members are private by default.
*/

class _ab{
private:
    struct _coord{
        int x{};
        int y{};
        int z{};
        int speed{};
    };

    _coord coordinates;

public:
    _ab(int x, int y, int z, int speed){
        this ->coordinates.x = x; //explicit access
        this ->coordinates.y = y;
        this ->coordinates.z = z;
        this ->coordinates.speed = speed;
    }
    
    void _getVal(){
        std::cout << coordinates.x << "," 
                  << coordinates.y << ","
                  << coordinates.z << ","
                  << coordinates.speed << std::endl;
    }
};

int main(){
    
    _ab ab(10,11,12,100);

    ab._getVal();

    return 0;
}