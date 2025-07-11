/* 
#28
Name: Arvin Liel Obayan
Date: 11/07/2025
*/

/* 
A list is similar to a vector in that it can store multiple elements of the same type and dynamically grow in size.

However, two major differences between lists and vectors are:

You can add and remove elements from both the beginning and at the end of a list, while vectors are generally optimized for adding and removing at the end.

Unlike vectors, a list does not support random access, meaning you cannot directly jump to a specific index, or access elements by index numbers.
To use a list, you have to include the <list> header file
*/

#include <iostream>
#include <list>

int main(){

    std::list<std::string> cars = {"Volvo", "Ford", "BMW", "Ferrari"};

    for(std::string car : cars){
        std::cout << car << " ";
    }

    //Access a list
    //You cannot access list elements by referring to index numbers, like with arrays and vectors.
    std::cout << std::endl;
    std::cout << cars.front() << std::endl;
    std::cout << cars.back() << std::endl;
    //change value of the first or last element in list
    cars.front() = "Mercedes";
    cars.back() = "Toyota";
    std::cout << cars.front() << std::endl;
    std::cout << cars.back() << std::endl;
    for(std::string car : cars){
        std::cout << car << " ";
    }

    //add list elements
    std::cout << "\n\n" << "Add list elements" << std::endl;
    for(int i = 0; i < 3; i++){
        auto add = [&](){
            std::string addElements;
            std::cout << "Enter element: ";
            std::cin >> addElements;
            cars.push_back(addElements);
        };
        add();
    }

    for(std::string car : cars){
        std::cout << car << " ";
    }

    //remove list elements
    std::cout << "\n\n" << "Remove list elements" << std::endl;
    for(int i = 0; i < 3; i++){
        auto remove = [&](){
            if(!cars.empty()){
                cars.pop_back();
            }
        };
        remove();
    }

    for(std::string car : cars){
        std::cout << car << " ";
    }

    



    return 0;
}