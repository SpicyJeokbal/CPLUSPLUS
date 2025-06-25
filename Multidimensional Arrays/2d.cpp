/* 
#7
Name: Arvin Liel Obayan
Date: 06/25/2025
*/


#include <iostream>
using namespace std;

int main(){

    int A[2][4], B[2][4], Sum[2][4];

    cout << "Matrix A" << endl;
    for (int i= 0; i < 2; i++){
        for(int j = 0; j < 4;j++){
            cout<<"Enter number: ";
            cin >> A[i][j];
        }
    }

    cout << "Matrix B" << endl;
    for (int i= 0; i < 2; i++){
        for(int j = 0; j < 4;j++){
            cout<<"Enter number: ";
            cin >> B[i][j];
        }
    }

    for (int i= 0; i < 2; i++){
        for(int j = 0; j < 4;j++){
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "Sum of Matrices A and B" << endl;
    for (int i= 0; i < 2; i++){
        for(int j = 0; j < 4;j++){
            cout << Sum[i][j] << " ";
        }
        cout << endl;
    } 

    

    return 0;
}


