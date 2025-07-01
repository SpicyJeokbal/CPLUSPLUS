/* 
#16
Name: Arvin Liel Obayan
Date: 06/26/2025
*/

#include <iostream>
#include <string>


//Access specifiers control how the members (attributes and methods) of a class can be accessed.
/* 
In C++, there are three access specifiers:
    public - members are accessible from outside the class
    private - members cannot be accessed (or viewed) from outside the class
    protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.
*/


//By default, all members of a class are private if you don't specify an access specifier:
class myClass{
    public:     
        int x;
    private:
        int y;

};


class Employee{
    protected:
        int salary;
};

class Programmer: public Employee{
    public:
        int bonus;
        void setSalary(int s){
            salary = s;
        }
        int getSalary(){
            return salary;
        }
};

int main(){

    Programmer p1;
    p1.setSalary(10000);
    p1.bonus = 1500;
    std::cout<< "Salary" << " " << p1.getSalary() << std::endl;
    std::cout<< "Salary" << " " << p1.bonus;

    return 0;
}