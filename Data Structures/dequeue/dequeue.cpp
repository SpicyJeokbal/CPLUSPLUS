/*
#31
Name: Arvin Liel Obayan
Date: 12/07/2025
*/

#include <iostream>
#include <deque>

void dequeSample(std::deque<std::string>& cars, std::string target){

    bool found = false;
    
    for(auto dequeIterator = cars.begin(); dequeIterator != cars.end(); dequeIterator++){
        if(*dequeIterator == target){
            found = true;
            cars.erase(dequeIterator);
            break;
        }
    }
    
    if(!found){
        std::cout << "Item " << target << " not found in deque\n";
    }


}



int main(){

    std::deque<std::string> cars;

    cars.push_back("Volvo");
    cars.push_back("BMW");
    cars.push_back("Mercedes Benz");
    cars.push_back("Ferrari");

    dequeSample(cars, "BMW");

    while(!cars.empty()){
        std::cout << cars.front() << std::endl;
        cars.pop_front();
    }


    return 0;
}