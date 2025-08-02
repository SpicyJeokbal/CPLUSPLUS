/*
#37
Name: Arvin Liel Obayan
Date: 02/08/2025
*/


#include <bits/stdc++.h>


/* The typedef keyword in C++ is used for aliasing existing data types, user-defined data types,
and pointers to a more meaningful name. Typedefs allow you to give descriptive names to standard
data types, which can also help you self-document your code. Mostly typedefs are used for aliasing,
only if the predefined name is too long or complex to write again and again.  The unnecessary use of typedef is generally not a good practice. */


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    typedef std::vector<int> vInt;

    // vec1 is a vector of 
    // type int
    vInt v;

    v.push_back(190);
    v.push_back(180);
    v.push_back(10);
    v.push_back(10);
    v.push_back(27);

    for (auto X : v) {
        std::cout << X << " ";
    }
    return 0;


}