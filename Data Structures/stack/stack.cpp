/* 
#29
Name: Arvin Liel Obayan
Date: 11/07/2025
*/

#include <iostream>
#include <stack>

void Whatever(std::stack<std::string>& cars, const std::string& target){
    //create another stack
    std::stack<std::string> dump;

    while(!cars.empty()){
        if(cars.top() == target){
            cars.pop();
            break;
        }
        dump.push(cars.top());
        cars.pop();
    }

    while(!dump.empty()){
        cars.push(dump.top());
        dump.pop();
    }


}

int main(){

    std::stack<std::string> cars;

    cars.push("Volvo");
    cars.push("Mazda");
    cars.push("Ferrari");
    cars.push("Mercedes Benz");

    Whatever(cars, "Mazda");

    while(!cars.empty()){
        std::cout << cars.top() << std::endl;
        cars.pop();
    }



    return 0;
}

/* 
d
c
b target
a

d
c
a 
*/