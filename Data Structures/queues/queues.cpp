/* 
#30
Name: Arvin Liel Obayan
Date: 11/07/2025
*/

#include <iostream>
#include <queue>

void Whatever(std::queue<std::string>& cars, const std::string& target){
    std::queue<std::string> dump;
    bool found = false;

    while(!cars.empty()){
        if(cars.front() == target){
            cars.pop();
            found = true;
            break;
        }
        dump.push(cars.front());
        cars.pop();
    }
    while(!dump.empty()){
        cars.push(dump.front());
        dump.pop();
    }

    if(!found){
        std::cout << "Element " << target << " not found in queue";
    }
}


int main(){

    std::queue<std::string> cars;

    cars.push("Volvo");
    cars.push("Ferrari");
    cars.push("Mercedes");
    cars.push("BMW");

    Whatever(cars, "Ferrari");

    while(!cars.empty()){
        std::cout << cars.front() << std::endl;
        cars.pop();
    }

    return 0;
}

/* 
volvo ferrari mercedes bmw

volvo mercedes bmw


*/