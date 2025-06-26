/* 
#12
Name: Arvin Liel Obayan
Date: 06/26/2025
*/

#include <iostream>
#include <string>

int sum(int k){
    if (k > 0){
        return k + sum(k-1);
    }
    else{
        return k;
    }
}

int factorial(int n){
    if(n > 1){
        return n * factorial(n-1);
    }
    else {
        return 1;
    }
}

int main(){

    int result = sum(10);
    std::cout << result <<  std::endl;

    std::cout << "Factorial of 5 is " << factorial(5);

    return 0;
}