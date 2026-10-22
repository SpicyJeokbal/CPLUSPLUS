/* 
#12
Name: Arvin Liel Obayan
Date: 06/26/2025
*/

#include <iostream>
#include <string>


//Function overloading allows multiple functions to have the same name, as long as their parameters are different in type or number:
//you cannot overload a function based on their return type

/* 
int sum(int a, int b);
double sum(int a, int b); error
*/

/* 
1. Too ambiguous
2. Makes code harder to maintain
3. Increases the compile time. The compiler checks all overload function and choose the best match,
   which adds complexity during compilation
*/


/* int plusFuncInt(int x, int y) {
  return x + y;
}

double plusFuncDouble(double x, double y) {
  return x + y;
} */


//WITHOUT FUNCTION OVERLOADING
/* int plusFuncInt(int x, int y) {
  return x + y;
}

double plusFuncDouble(double x, double y) {
  return x + y;
}

int main() {
  int myNum1 = plusFuncInt(8, 5);
  double myNum2 = plusFuncDouble(4.3, 6.26);

  cout << "Int: " << myNum1 << "\n";
  cout << "Double: " << myNum2;
  return 0;
} */

//FUNCTION OVERLOADING
/* int plusFunc(int x, int y) {
  return x + y;
}

double plusFunc(double x, double y) {
  return x + y;
}

int main() {
  int myNum1 = plusFunc(8, 5);
  double myNum2 = plusFunc(4.3, 6.26);

  cout << "Int: " << myNum1 << "\n";
  cout << "Double: " << myNum2;
  return 0;
} */

int plusFunct(int x, int y){
    return x + y;
}

int plusFunct(int x, int y, int z){
    return x + y + z;
}


int main(){

    int result1 = plusFunct(7,3);
    int result2 = plusFunct(7,3,10);
    
    std::cout << result1 << "\n" << result2;


    return 0;
}