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
*/


//inline constructor
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

};

//constructor declared inside but defined outside
class Name{

    public:
        std::string Fname;
        std::string Lname;
        int age;
        Name(std::string x, std::string y, int z);

};

Name::Name(std::string x, std::string y, int z){
    Fname = x;
    Lname = y;
    age = z;
}


//constructor overloading

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