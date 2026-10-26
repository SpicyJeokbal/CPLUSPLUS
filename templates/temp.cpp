/* 
#102
Name: Liyel
Date: 10/26/2026
*/

#include <iostream>

/* 
templates let you write one function that works for different
data types, instead of writing separate version for int, double.
string, and so on.
*/

//problem that templates solve:
//the logic is still the same. Only the data type changes.
/* int getBigger(int a, int b){
    return (a > b) ? a : b;
}

double getBigger(double a, double b){
    return (a > b) ? a : b;
} */

//template
/* 
template - means you're creating a reusable blueprint
typename - tells the program that T represents a type
T - is a placeholder. You could call it `type`, `whatever`, or another
    valid identifier, but `T` is conventional.
    Think of `T` as an empty box waiting for a data type.

T getBigger(T a, T b)
The first T: the function's return type
Second T: the type of parameter a   
Third T: the type of parameter b   
*/


template <typename T>
T getBigger(T a, T b){
    return (a > b) ? a : b;
}



int main(){


    //template argument deduction
    //when you call the line of code below, the program figures out
    //the T should be int
    std::cout << getBigger(10,20) << std::endl;
    //when you call the line of code below, the program figures out
    //the T should be double
    std::cout << getBigger(10.0,20.1) << std::endl;

    //you can also specify the type yourself:
    std::cout << getBigger<double>(1,2) << std::endl;
    
    
    return 0;
}