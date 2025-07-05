/* 
#22
Name: Arvin Liel Obayan
Date: 07/01/2025
*/


#include <iostream>


class Animal {
  public:
    virtual void sound() {
      std::cout << "Animal sound\n";
    }
};

class Dog : public Animal {
  public:
    void sound() {
      std::cout << "Dog barks\n";
    }
};

int main() {
  Animal* a;  // Declare a pointer to the base class (Animal)
  Dog d;  // Create an object of the derived class (Dog)
  a = &d;  // Point the base class pointer to the Dog object
  a->sound(); // Call the sound() function using the pointer. Since sound() is not virtual, this calls Animal's version
  return 0;
}