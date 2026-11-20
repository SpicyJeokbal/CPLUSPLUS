#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

//mutext(mutual exclusion) is an object that allows only one thread
//at a time to access a piece of code or shared data

void work(int id){
    //Without `mutex` or `lock_guard` the threads may access it at the same time
    //causing overlap. With mutex, it only allows one thread to access this function
    //before it gives it access to another thread. Basically one thread at a time
    std::lock_guard<std::mutex> guard(m); //lock until function ends

    //lock guard is recommended to use alongside mutex as it automatically unlocks
    //the mutex unlike when it's not being used, you have to manually unlock it.
    
    //m.lock();
    std::cout << "Thread " << id << " is working\n";
    //m.unlock();
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