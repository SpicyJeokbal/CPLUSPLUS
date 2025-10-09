

#include <iostream>
#include <thread>
#include <chrono>

void task1(){
    std::cout << "Thread 1 is running. ID: " << std::this_thread::get_id() << "\n";   
    //std::this_thread::get_id() is used inside of a thread
}

void task2(){
    std::cout << "Thread 2 is running. ID: " << std::this_thread::get_id() << "\n";
}


int main(){
    
    std::thread t1(task1);
    std::thread t2(task2);

    std::cout << "T1 id: " << t1.get_id() << "\n";
    //get_id is used outside of a thread to get the threads ID
    std::cout << "T2 id: " << t2.get_id() << "\n";


    if(t1.joinable()){
        t1.join();
        std::cout << "Thread 1 joined\n";
    }

    if(t2.joinable()){
        t2.detach();
        std::cout << "Thread 2 detached\n";
    }

    std::cout << "Main thread sleeping for 1 second\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Main thread is awake\n";



    return 0;
}