#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    string greeting = "hello ", name = "Cailegh", surname = " Winters", fullname = name.append(surname);
    string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string sample = "We are the so-called \"Vikings\" from the north.";
    string Fullname;


    cout << greeting + name << endl;
    cout << fullname << endl;
    cout << txt.length() << endl;
    cout << txt.size() << endl;
    cout << txt[txt.length() - 1] << endl;
    cout << sample << endl;

    cout << "Enter your fullname: ";
    cin >> Fullname; // cin considers white space as a terminating character, which means it can only store a single word

    cout << "Enter your fullname: ";
    getline(cin, fullname); 
    /*That's why, when working with strings, we often use the getline()
    function to read a line of text. It takes cin as the first parameter, and the string variable as second:*/


    return 0;
}
