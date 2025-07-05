/* 
#25
Name: Arvin Liel Obayan
Date: 07/05/2025
*/

#include <iostream>
#include <ctime>


int main(){

    /* time_t timestamp;    
    time(&timestamp);   //stored in heap memory       

    std::cout << ctime(&timestamp); */

    //this is the same as above, but this one does not store the time
    time_t timestamp = time(NULL);  //stored in stack memory

    std::cout << timestamp; //returns current time in seconds since Jan 1, 1970

    return 0;
}
