/* 
#8
Name: Arvin Liel Obayan
Date: 06/25/2025
*/

#include <iostream>
using namespace std;

struct  Student
{
    string Name;
    int IdNumber;
    float GPA;
};


int main(){

    //used to group different variables even if they're different data types

    //stored in stack memory. temporary stuff
    Student s1[3];
    for(int i = 0; i < 3; i++){
        cout <<"Name: ";
        cin >> s1[i].Name;
        cout <<"ID: ";
        cin >> s1[i].IdNumber;
        cout << "GPA: ";
        cin >> s1[i].GPA;
    }

    for(int i = 0; i < 3; i++){
        cout <<s1[i].Name << "\t" << s1[i].IdNumber << "\t" << s1[i].GPA << endl;
        
    }

    //stored in heap memory. Stuff stays until you say so(delete)

    Student* s2[3]; //create an instance first and assign a pointer to it.

    for(int i = 0; i < 3; i++){
        s2[i] = new Student; //point Student

        cout << "Name: ";
        cin >> s2[i]->Name;

        cout << "ID: ";
        cin >> s2[i]->IdNumber;

        cout << "GPA: ";
        cin >> s2[i]->GPA;
        
    }

    for(int i = 0; i < 3; i++){
        cout << s2[i]->Name << "\t" << s2[i]->IdNumber << "\t" << s2[i]->GPA << endl;
    }
    

    



    return 0;
}