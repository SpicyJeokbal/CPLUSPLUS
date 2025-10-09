

#include <iostream>
#include <thread>

int main(){
    
    int n = 3;

    std::thread t([](int n){
        std::cout << n;
    }, n);

    t.join();

    return 0;
}