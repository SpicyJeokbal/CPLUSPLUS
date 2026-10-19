
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

namespace _namespaceA{
    int x{10};
}

namespace _namespaceB{
    int x{20};

    struct _users{
        std::string _name;
        int age{};
    };
}

 

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    _namespaceB::_users user;

    int x{1};

    /* std::cout << _namespaceA::x << std::endl;
    std::cout << _namespaceB::x << std::endl;
    std::cout << x; */

    std::cout << "Name: ";
    std::getline(std::cin, user._name);

    std::cout << "Age: ";
    std::cin >> user.age;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::cout << user._name << "\t" << user.age << std::endl;

}