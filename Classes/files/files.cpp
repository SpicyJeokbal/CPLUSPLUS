/* 
#24
Name: Arvin Liel Obayan
Date: 07/05/2025
*/


#include <iostream>
#include <fstream>

//ofstream  -   creates and writes to file
//ifstream  -   reads from files
//fstream   -   combination of ofstream and ifstream


void write(){
    //create and open a text file
    std::ofstream MyFile("Filename.txt");

    MyFile << "Hello world";

    MyFile.close();
    /* 
    Why do we close the file?
    It is considered good practice, and it can clean up unnecessary memory space.
    */
}




void read(){
    std::ifstream MyReadFile("Filename.txt");
    if(MyReadFile.is_open()){
        std::string line;
        while(std::getline(MyReadFile, line)){
            std:: cout << line;
        }
        MyReadFile.close();
    } else {
        std::cout << "file not found";
    }
}

int main(){

    
    

    write();
    read();


    return 0;
}