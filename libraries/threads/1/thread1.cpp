

#include <iostream>
#include <thread>


void sayHello(){
    std::cout << "hello\n";
}




int main(){
    
    std::thread t1(sayHello);

    t1.join(); //main waits for 't1' to finish

    
    std::cout << "back to the main program\n";

    return 0;
}