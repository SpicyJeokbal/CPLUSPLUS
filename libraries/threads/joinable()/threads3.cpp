

#include <iostream>
#include <thread>

void func(){
    std::cout << "Thread is working\n";
}

int main(){
    
    std::thread t1(func);

    if(t1.joinable()){
        std::cout << "Thread can be joined.\n";
        t1.join();
    }

    if(!t1.joinable()){
        std::cout << "Thread cannot be joined.\n";
    }


    return 0;
}