

#include <iostream>
#include <thread>
#include <chrono>

void func(){
    std::cout << "Thread is working\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread finished work\n";
}


int main(){
    
    std::thread t1(func);

    std::cout << t1.get_id() << "\n";

    t1.detach();

    std::cout << "Main thread is done\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}