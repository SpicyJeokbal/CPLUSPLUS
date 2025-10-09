

#include <iostream>
#include <thread>

void func(int n){
    std::cout << n;
}

int main(){
    
    std::thread t1(func,5);
    std::thread t2(func,5);
    std::thread t3(func,5);
    std::thread t4(func,5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}