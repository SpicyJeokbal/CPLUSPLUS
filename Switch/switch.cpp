/* 
#4
Name: Arvin Liel Obayan
Date: 06/24/2025
*/

#include <iostream>
using namespace std;

int main(){

    /* Switch Case */
    int choice; 
    cout << "Enter a number: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "You chose burger" << endl;
        break;
    case 2:
        cout << "You chose pizza" << endl;
        break;
    case 3:
        cout << "You chose croissant" << endl;
        break;
    
    default:
        cout<< "?" << endl;
        break;
    }

    return 0;
}