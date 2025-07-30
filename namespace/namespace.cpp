
/*
#36
Name: Arvin Liel Obayan
Date: 30/07/2025
*/

//A namespace is a way to group related code together under a name. It helps you avoid naming conflicts when your code grows or when you use code from multiple sources.
//Think of a namespace like a folder: you can have a variable named x in two different folders, and they won't clash.

/* Why Use Namespaces?
To avoid name conflicts, especially in larger projects
To organize code into logical groups
To separate your code from code in libraries */

#include <bits/stdc++.h>

namespace mynameSpace{
    int x = 42;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int x = 1;

    std::cout << mynameSpace::x;




}