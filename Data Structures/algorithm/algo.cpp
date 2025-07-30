
/*
#35
Name: Arvin Liel Obayan
Date: 28/07/2025
*/

#include <bits/stdc++.h>
//#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> numbers = {5, 8, 2, 4, 10, 13};

    //start_iterator, end_iterator, value
    auto it = find(numbers.begin(), numbers.end(), 4);

    std::cout << *it << "\n";

    //To search for the first element that is greater than a specific value, you can use the upper_bound() function:
    sort(numbers.begin(), numbers.end());

    auto xy = upper_bound(numbers.begin(), numbers.end(), 5);

    std::cout << *xy << "\n";

    //To find the smallest element in a vector, use the min_element() function:     max_element to find the largest num
    auto xz = min_element(numbers.begin(), numbers.end());

    std::cout << *xz << "\n";

    std:: cout << "\n";
    //copy elements from one vector to another
    std::vector<int> copiedNumber(6);

    copy(numbers.begin(), numbers.end(), copiedNumber.begin());

    for(int x : copiedNumber){
        std::cout << x << "\n";
    }

    //fill all elements in the numbers with whatever

    std::vector<int>  whatever(6);

    fill(whatever.begin(), whatever.end(), 5);

    for(int y : whatever){
        std::cout << y << "\n";
    }





    
}