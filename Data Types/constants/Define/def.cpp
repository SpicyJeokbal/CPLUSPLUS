#include <iostream>

/* 
#define is a preprocessor macro. It allows programmers to assign name to a constant value or a piece of code.
Before compilation, the preprocessor replaces occurences of the macro name with its defined replacement text.

connect(SSID) becomes connect("QwOp_AP")

- #define is commonly used to define symbolic constants and function like macros
- unlike variables and functions, macros do not provide type checking
- STRICTLY NO SEMICOLONS UNLESS NEEDED cause its going to be part of the macro

*/

#define SSID "QwOp_AP"
#define PASSWORD "AP_2904"
#define SQUARE(x) ((x)*(x))

int main(){
    
    std::cout << SSID << std::endl;
    std::cout << SQUARE(2) << std::endl;
    return 0;
}