/* 
#12
Name: Arvin Liel Obayan
Date: 06/26/2025
*/


#include <iostream>
#include <string>
#include <functional>

/* 
A lambda function is a small, anonymous function you can write directly in your code. 
It's useful when you need a quick function without naming it or declaring it separately.
Syntax
capture list controls outside variables
[capture] (parameters) { code };
*/

/* Use a lambda function when:
You only need the function once
The code is short and simple
You want to pass a quick function into another function */



//myFunction is expecting a lambda, function pointer, or functor as a parameter
void myFunction(std::function<void()>func){
    func();
    func();
}

int main(){

    auto message = [](){
        std::cout << "Hello world"  << std::endl;
    };

    message();

    auto add = [](int a, int b){
        return a + b;
    };

    std::cout << add(1,2) << std::endl;

    //passing lambdas to functions
    myFunction(message);

    //lambdas with loops
    for (int i = 0; i < 3; i++){
        auto show = [i](){
            std::cout << i << std::endl;
        };
        show();
    }

    //capture by reference
    int x = 10;
    auto edit = [&x](){
        std::cout << x;
    };
    x = 20;

    edit();

    return 0;

}