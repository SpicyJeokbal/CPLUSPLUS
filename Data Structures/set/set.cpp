/*
#32
Name: Arvin Liel Obayan
Date: 12/07/2025
*/


/* 
A set stores unique elements where they:
Are sorted automatically in ascending order.
Are unique, meaning equal or duplicate values are ignored.
Can be added or removed, but the value of an existing element cannot be changed.
Cannot be accessed by index numbers, because the order is based on sorting and not indexing.
*/


#include <iostream>
#include <set>


void setPeeking(std::set<int>& num, int target){

    bool targetFound = false;

    auto setIterator = num.find(target);
    if(setIterator != num.end()){
        num.erase(*setIterator);
    } 
    else{
        std::cout << target << " not found in set \n";
    }

}

int main(){

    std::set<int> num;

    num.insert(1);
    num.insert(12);
    num.insert(3);
    num.insert(6);
    num.insert(5);
    num.insert(10);
    num.insert(7);
    num.insert(7);

    setPeeking(num, 10);

    for(int sample : num){
        std::cout << sample << "\n";
    }

    return 0;
}