/*
#34
Name: Arvin Liel Obayan
Date: 28/07/2025
*/

#include <bits/stdc++.h>

int main(){
     std::ios_base::sync_with_stdio(false);
     std::cin.tie(nullptr);
    
     std::vector<std::string> cars = {"Volvo", "BMW", "Mazda", "Ferrari"};

     std::vector<std::string>::iterator it;

    for(it = cars.begin(); it != cars.end(); ++it){
        std::cout << *it << "\n";
    }

    std::cout << "\n";

    std::sort(cars.begin(), cars.end());

    for (std::string car : cars){
        std::cout << car << "\n";
    }

    
}