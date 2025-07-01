/* 
#17
Name: Arvin Liel Obayan
Date: 06/26/2025
*/

#include <iostream>
#include <string>

/* 
The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users.

To achieve this, you must declare class variables/attributes as private (cannot be accessed from outside the class).

If you want others to read or modify the value of a private member, you can provide public get and set methods.
*/


class Employee{

    private:
        int salary;

    public:
        //setter
        void setSalary(int s){
            salary = s;
        }
        //getter
        int getSalary(){
            return salary;
        }

};

//friend function
/* 
Normally, private members of a class can only be accessed using public methods like getters and setters.
But in some cases, you can use a special function called a friend function to access them directly.
A friend function is not a member of the class, but it is allowed to access the class's private data
*/

class Name{
    private:
        std::string Fname;
        std::string Lname;
        int age;
    public:
        Name(std::string x, std::string y, int z){
            Fname = x;
            Lname = y;
            age = z;
        }

        //declare friend function
        friend void displayName(Name name);
};

void displayName(Name name){
    std::cout << name.Fname << " " << name.Lname << " " << name.age << std::endl;
}


int main(){

    Employee employee;
    employee.setSalary(1000);
    std::cout << employee.getSalary();

    std::cout << std::endl;
    
    Name name("Sebastian", "Castellanos", 32);
    displayName(name);



    return 0;

}
