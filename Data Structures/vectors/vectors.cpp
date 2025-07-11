/* 
#27
Name: Arvin Liel Obayan
Date: 11/07/2025
*/


#include <iostream>
#include <vector>

/* 
The difference between an array and a vector, is that the size of an array cannot be modified (you cannot add or remove elements from an array). 
A vector however, can grow or shrink in size as needed.
To use a vector, you have to include the <vector> header file
*/

template <typename T>
void printVector(const std::vector<T>& cars){
    for(const T& item:cars){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


int main(){

    std::vector <std::string> carBrands = {"Volvo", "Ford", "Volvo", "BMW"};
    //access an element in a vector
/*  std::cout << carBrands[1] << std::endl;*/   
    std::cout << carBrands.at(0) << std::endl; //safer to use than above cause it lets you know if an error occurs

    std::cout << carBrands.front() << std::endl;
    std::cout << carBrands.back() << std:: endl;
     
    //change a vector element
    carBrands.at(0) = "Ferrari";

    //add a vector element
    for(int i = 0; i < 3; i++){
        auto add = [&](){   //& captures everything by reference
            std::string addElement;
            std::cout << "Vector element to add: ";
            std::cin >> addElement;
            carBrands.push_back(addElement);    //used to add elements 
        };
        add();
    }
    std::cout << "\nAdded elements" << std::endl;
    std::cout << carBrands.size() << std::endl;
    printVector(carBrands);
    
    //remove a vector element
    for(int i = 0; i < 3; i++){
        auto remove = [&](){   //& captures everything by reference
            if(!carBrands.empty()){
                carBrands.pop_back();
            }
        };
        remove();
    }

    std::cout << "\nRemoved added elements" << std::endl;
    std::cout << carBrands.size() << std::endl;
    printVector(carBrands);


    //check if vector is empty
    std::cout << carBrands.empty() << std::endl; // 0 if no, 1 if yes

    printVector(carBrands);

    
    


    return 0;
}