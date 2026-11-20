

#include <iostream>
#include <thread>

void func(){
    std::cout << "Thread is working\n";
}

int main(){
    
    std::thread t1(func);

    //checks if the thread is still assigned to you
    //if the thread is left unattended, the program will terminate

    //if it returns `true` then the thread is still assigned to you. You must
    //call `join()` or `detach()` to terminate it properly.
    if(t1.joinable()){
        std::cout << "Thread can be joined.\n";
        t1.join();
    }

    //if it returns `false` then the thread has been terminated properly,
    //either by `join()` or `detach()`
    if(!t1.joinable()){
        std::cout << "Thread cannot be joined.\n";
    }


    return 0;
}