/* 
#19
Name: Arvin Liel Obayan
Date: 07/01/2025
*/

#include <iostream>

/* 
Multilevel Inheritance
A class can also be derived from one class, which is already derived from another class.
In the following example, MyGrandChild is derived from class MyChild (which is derived from MyClass).
*/

class MyClass{
    public:
        void MyFunction(){
            std::cout<<"this is the parent class";
        }
};

class MyChild: public MyClass{

};

class MyGrandChild: public  MyChild{

};




int main(){

    MyGrandChild myObj;
    myObj.MyFunction();


    return 0;
}