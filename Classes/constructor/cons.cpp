/* 
#15
Name: Arvin Liel Obayan
Date: 06/26/2025
*/

#include <iostream>
#include <string>

/* 
Constructor Rules
    The constructor has the same name as the class.
    It has no return type (not even void).
    It is usually declared public.
    It is automatically called when an object is created.
    Must declare the variables before the constructor can use it
*/

/* 
A constructor is a convenient way to guarantee that an object
starts with the values you want. It isn't mandatory, but you
should never use an uninitialized variable or member expecting
it to contain a meaningful value.

A class constructor initializes an object when created, so you
dont have to manually assign each member variable afterward. 
Basically, you create the object first, then assign its value 
one by one.

With constructor, creating an object automatically initializes its
member variables using the values you provide. No manual assigning
afterward.

In the instance, you just have to provide the values when creating
the object, and the constructor assigns those values to the objects
for you.
*/

/* 
A constructor acts like a middleman that initializes an object's values for you when you create it.

*/



//===========inline constructor===========
/* 
Essentially, the same as inside class definition(found in class.cpp #14)
*/
class Car{

    public:
        std::string brand;
        std::string model;
        int year;

        Car(std::string x, std::string y, int z){
            brand = x;
            model = y;
            year = z;
        }
        /* 
        Car(std::string x, std::string y, int z) : brand(x), model(y), year(z) {}
        */
};

//===========Outside defined constructor===========
/* 
Essentially, the same as outside class definition(found in class.cpp #14)
 */
class Name{

    public:
        std::string Fname;
        std::string Lname;
        int age;
        Name(std::string x, std::string y, int z);

};

/* 
Scope resolution operator, used to define an outside constructor 
*/
Name::Name(std::string x, std::string y, int z){
    Fname = x;
    Lname = y;
    age = z;
}


//===========constructor overloading===========

class Phone{
    public:
        std::string brand;
        std::string model;
        int year;

        Phone(){
            brand = "Samsung";
            model =  "S25";
            year = 2020;
        }

        Phone(std::string b, std::string m, int z){
            brand = b;
            model = m;
            year = z;
        }
};




int main(){

    Car car1("BMW", "X5", 2010);
    Car car2("Ford", "Mustang", 2013);

    std::cout << "Inline Constructor" << std::endl;
    std::cout << car1.brand << " " << car1.model << " " << car1.year << std::endl;
    std::cout << car2.brand << " " << car2.model << " " << car2.year << std::endl;
    std::cout << std::endl;
    
    Name name1("Sebastian", "Castellanos", 32);
    Name name2("John", "Doe", 32);

    std::cout << "Constructor defined outside" << std::endl;
    std::cout << name1.Fname << " " << name1.Lname << " " << name1.age << std::endl;
    std::cout << name2.Fname << " " << name2.Lname << " " << name2.age << std::endl;
    std::cout << std::endl;


    Phone phone1;
    Phone phone2("Iphone", "XR", 2020);
    Phone phone3("Iphone", "15", 2025);

    std::cout << "Constructor overloading" << std::endl;
    std::cout << phone1.brand << " " << phone1.model << " " << phone1.year << std::endl;
    std::cout << phone2.brand << " " << phone2.model << " " << phone2.year << std::endl;
    std::cout << phone3.brand << " " << phone3.model << " " << phone3.year << std::endl;
    



    return 0;

}