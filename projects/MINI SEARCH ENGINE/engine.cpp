
#include <iostream>
#include <string>
#include <limits>
#include "record.h"

/* 
list
add
search
delete
*/

searchEngine::Database inputBook();

int main(){
    

    
    searchEngine engine;
    int choice{};


    do{
        std::cout << "\n1.) Show list\n2.) Add book\n3.) Search book\n4.) Delete book\n Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
    
        switch (choice)
        {
        case 1:
            engine.displayRecords();
            break;
        case 2: {
                //SCOPE PATH
                searchEngine::Database db = inputBook();
                engine.addRecord(db);
                break;
            }
        case 3:
            engine.searchItem();
            break;
        case 4:
            engine.deleteBook();
            break;
        case 5:
            break;

        default:
            std::cout << "Input valid choice\n";
            break;
        }

    }while(choice != 5);




    return 0;
}

searchEngine::Database inputBook(){
    searchEngine::Database db;
   
    std::cout << "Enter title: ";
    std::getline(std::cin, db.Title);

    std::cout << "Author's name: ";
    std::getline(std::cin, db.Author);

    std::cout << "Year published: ";
    std::cin >> db.year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //flush leftover left by >>db.year

    std::cout << "Genre: ";
    std::getline(std::cin, db.genre);

    return db;

}