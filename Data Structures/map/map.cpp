/*
#33
Name: Arvin Liel Obayan
Date: 17/07/2025
*/

//same concept as dictionary in python

#include <iostream>
#include <map>


void addMap(std::map<std::string, int>& people){

    std::string name;
    int age, count;

    std::cout << "How many data are you going to insert? ";
    std::cin >> count;
    std::cin.ignore();

    for(int i = 0; i < count; i++){
        std::cout << "Name: ";
        std::getline(std::cin, name);

        std::cout << "Age: ";
        std::cin >> age;
        std::cin.ignore();

        people.insert({name, age});
    }
}

void readMap(std::map<std::string, int>& people){

    for(const auto& [Readname, Readage] : people){
        std::cout << Readname << " " << Readage << "\n";
    }
}

void removeItem(std::map<std::string, int>& people, const std::string& target){

    if (people.erase(target)) {
        std::cout << target << " has been removed.\n";
    } else {
        std::cout << target << " not found in the map.\n";
    }   

}



int main(){

    std::string target;
    int choice;

    std::map<std::string, int> people = {};

    

    do{

        std::cout << "1.)Read map \n2.) Add item \n3.) Remove item \n";
        std::cin >> choice;

        switch(choice){
            case 1:
                if(!people.empty()){
                    readMap(people);
                }
                else{
                    std::cout << "Map is empty \n";
                }
                break;

            case 2:
                addMap(people);
                break;
            case 3:
                if(!people.empty()){
                    readMap(people);
                    std::cout << "\n Item to be remove: ";
                    std::cin >> target;
                    removeItem(people, target);
                    readMap(people);
                }
                else{
                    std::cout << "Map is empty";    
                }
                break;
            default:
                std::cout << "bitch";
        }
    }while(choice != 4);


    return 0;
}