/* 
#18
Name: Arvin Liel Obayan
Date: 07/01/2025
*/

//#pragma once is also an option if you dont want the one below


#ifndef HEADER_H //if header.h is not yet define then
#define HEADER_H // define header.h

#include <iostream>

class Name{

    private:
        std::string Fname;
        std::string Lname;
        int age;

    public:
        //setter
        void SetName(std::string x, std::string y, int z){
            Fname = x;
            Lname = y;
            age = z;
        }

        void GetName(){
            std::cout << Fname << " " << Lname << " " << age;
        }


};



#endif  //end of header.h