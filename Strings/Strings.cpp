#include <iostream>
using namespace std;

int main()
{
    
    string greeting = "hello ", name = "Cailegh", surname = " Winters", fullname = name.append(surname);

    cout << greeting + name << endl;
    cout << fullname;


    return 0;
}
