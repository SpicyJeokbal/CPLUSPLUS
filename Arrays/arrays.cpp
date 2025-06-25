/* 
#6
Name: Arvin Liel Obayan
Date: 06/24/2025
*/


#include <iostream>
using namespace std;

int main(){

    string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
    

    for(int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++){
        cout << cars[i] << endl;
    }

    cout << endl;

    for (string car : cars) {
        cout << car << endl;
    }

    //find how many elements an array has
    int number[5] = {10, 20, 30, 40, 50};
    int getArrayLength = sizeof(number) / sizeof(number[0]);
    cout << getArrayLength << endl;




    return 0;
}