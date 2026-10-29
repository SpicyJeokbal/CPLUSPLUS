#include <iostream>
#include <array>

/* 
Was bored, so I created a code that used the ff:class, class access specifiers, 
constructor overloading, and arrays 
*/



class _ab{
protected:
    struct _s{
        int x{};
        int y{};
        int z{};
        int speed{};

        _s(int _x, int _y, int _z, int _speed)
            : x(_x), y(_y), z(_z), speed(_speed){}
    };
    _s s;

private:
    struct _v{
        int i{};
        int j{};
        int k{};
        int velocity{};

        _v(int _i, int _j, int _k, int _velocity)
            : i(_i), j(_j), k(_k), velocity(_velocity){}
    };
    _v v;

public:
    //constructor for both structs
    _ab(int _x_coord, int _y_coord, int _z_coord, int _speed_)
        : s(_x_coord, _y_coord, _z_coord, _speed_)
        , v(_x_coord, _y_coord, _z_coord, _speed_) {};

    //constructor overloading
    /* 
    It may look like it's not working, but, it's actually working. It takes these parameters
    (int, int, int, float), but, the struct _v has a parameter of (int, int, int, int), the float
    is converted into an int
    */
    _ab(int _a, int _b, int _c, float _spd)
        :s(_a, _b, _c, _spd)
        ,v(0,0,0,0){};
         
    //fetch struct _s's data
    void _get_s_coords(){
         std::cout << s.x << ", "
                   << s.y << ", "
                   << s.z << ", "
                   << s.speed << std::endl;
    }

    //fetch struct _v's data
    void _get_v_coords(){
        std::cout << v.i << ", "
                   << v.j << ", "
                   << v.k << ", "
                   << v.velocity << std::endl;
    }

    //set struct _v's data
    void _set_v_coords(int val_a, int val_b, int val_c, int val_d){
        this ->v.i = val_a;
        this ->v.j = val_b;
        this ->v.k = val_c;
        this ->v.velocity = val_d;
    }

};


void _input_coords(){

    std::array<int, 4> _iter{};
    std::array<std::string,4> _iter_words{
        "x-coord",
        "y-coord",
        "z-coord",
        "speed"
    };

    for(size_t i{}; i < _iter.size(); i++){
        std::cout << "Enter " << _iter_words[i] << " :";
        std::cin >> _iter[i];
    }

    _ab ab(_iter[0], _iter[1], _iter[2], _iter[3]);

    ab._get_s_coords();
    
    ab._get_v_coords();

}


int main(){
    
    int _ans_x{}, _ans_y{}, _ans_z{}, _ans_speed{};

    _input_coords();

    //overloaded constructor
    _ab _ab_(1,1,1,20);
    _ab_._get_s_coords();
    
    //setter
    _ab __ab(2,2,2,20);
    __ab._set_v_coords(2,2,2,20.0);
    __ab._get_v_coords();
    
    return 0;
}