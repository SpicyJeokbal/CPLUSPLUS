/* 
#11
Name: Arvin Liel Obayan
Date: 06/26/2025
*/

#include <iostream>
#include <string>

//pass by reference
void swapnums(int &x, int &y){

    int z = x;
    x = y;
    y = z;

}

//pass arrays as functions
void myFunc(int myNumbers[], int ArrSize){
    for(int i = 0; i < ArrSize; i++){
        std::cout << myNumbers[i] << "\n";
    }
}

//pass struct on a function
struct Car{
    std::string brand;
    int year;
};

void updateYear(Car& c){
    c.year++;
}


//car c is the copy of the instance myCar
void CarFunction(Car c, void (*func)(Car&)){
    func(c); // call the function passed in
    std::cout << c.brand << "\n" << c.year << "\n";
}
/* 
void (*func)(Car&) → says “this parameter is a pointer to a function that takes a Car& and returns void”
*/


int main(){
    int firstNum = 10;
    int SecondNum = 20;

    std::cout <<"Before swap: " << "\n";
    std::cout << firstNum << SecondNum << "\n";

    swapnums(firstNum, SecondNum);

    std::cout <<"After swap: " << "\n";
    std::cout << firstNum << SecondNum << "\n";

    int myNumbers[5] = {10,20,30,40,50};
    int ArrSize = sizeof(myNumbers) / sizeof(myNumbers[0]);
    myFunc(myNumbers, ArrSize);

    Car myCar = {"Ferrari", 2018}; //create an instance of Car 
    CarFunction(myCar, updateYear);


    return 0;   
}
