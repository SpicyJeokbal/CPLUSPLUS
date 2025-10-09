#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

void work(int id){
    std::lock_guard<std::mutex> guard(m); //lock until function ends
    std::cout << "Thread " << id << " is working\n";
}


int main(){

    std::thread th1(work, 1);
    std::thread th2(work, 2);
    std::thread th3(work, 3);

    th1.join();
    th2.join();
    th3.join();
 
    std::cout << "back to the main program\n";

    return 0;
}