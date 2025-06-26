#include <iostream>
#include <string>


int main(){

    int students;
    std::cout << "how many students: ";
    std::cin >> students;

    if(students <= 0){
        std::cout << "Numbers of students must be at least 1 \n";
    }

    std::string* guests = new std::string[students]; //create an instance of students   
    
    for(int i = 0; i < students; i++){
        std::cout << "Enter students name: ";
        std::cin >> guests[i];
    }

    std::cout << "List of all guests" << std::endl;
    for(int i = 0; i < students; i++){
        std::cout << guests[i] << std::endl;
    }

    delete[] guests;

    return 0;
    
}