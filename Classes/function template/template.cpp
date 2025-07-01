/* 
#23
Name: Arvin Liel Obayan
Date: 07/01/2025
*/


#include <iostream>


/* 
template functions are basically the "choose your own type" 
version of normal functions — compiler fills in the blanks at compile-time.
*/

template <typename T>
T add(T a, T b){    //type is deduced when you call the function
    return a + b;
}

template <typename U, typename V>
void printPair(U a, V b){
    std::cout << "First " << a << ", Second " << b;
}


int main(){

    std::cout << add(3,4) << std::endl;
    printPair(42, std::string("Leigh"));

    return 0;
}