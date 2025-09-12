

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm> //lib for find and sort

void addBookName(std::vector<std::string>& bookList);
void readFile();
void readVectorContents();
void loadBooks(std::vector <std::string>& bookList);
void deleteBook(std::vector<std::string>& bookList);
void searchItem(std::vector <std::string>& bookList);
void editBookTitle(std::vector <std::string>& bookList);

int main(){
    
    std::vector <std::string> bookList{};

    int choice{};

    loadBooks(bookList);


    do{
        std::cout << "\n--- Book Menu ---\n";
        std::cout << "1. Add a book\n";
        std::cout << "2. Show file contents\n";
        std::cout << "3. Delete Book\n";
        std::cout << "4. Search Item\n";
        std::cout << "5. Edit Item\n";
        std::cout << "6. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice)
        {
        case 1:
            addBookName(bookList);
            break;
        case 2:
            readVectorContents(bookList);
            break;
        case 3:
            readFile();
            deleteBook(bookList);
            readFile();
            break;
        case 4:
            searchItem(bookList);
            break;
        case 5:
            editBookTitle(bookList);
            break;
        case 6:
            std::cout << "Biyatch\n";
            break;
        default:
            std::cout << "Invalid input\n";
            break;
        }
    } while (choice != 6);
    
    return 0;

}

void addBookName(std::vector<std::string>& bookList){

    std::ofstream WriteFile("BookName.txt", std::ios::app);
    std::string bookName{};

    if(WriteFile.is_open()){
        std::cout << "Enter Book title: ";
        std::getline(std::cin, bookName);

        if(std::find(bookList.begin(), bookList.end(), bookName) != bookList.end()){
            std::cout << "Book already exists\n";
            return;
        }
        else{
            WriteFile << bookName << "\n";
            bookList.push_back(bookName);
        }
        WriteFile.close();
        std::cout << "Content added to Bookname.txt\n";
    }
    else{
        std::cerr << "error opening file\n";
    }

}

void readFile(){
    std::ifstream MyReadFile("BookName.txt");
    if(MyReadFile.is_open()){
        std::string line;
        while(std::getline(MyReadFile, line)){
            std:: cout << line << "\n";
        }
        MyReadFile.close();
    } else {
        std::cout << "file not found\n";
    }
}

void readVectorContents(std::vector <std::string>& bookList){
    std::sort(bookList.begin(), bookList.end());

    for (auto& readFile : bookList){
        std::cout << readFile << "\n";
    }
}


//load file contents into the vector
void loadBooks(std::vector <std::string>& bookList){
    std::ifstream MyReadFile("BookName.txt");
    if(MyReadFile.is_open()){
        std::string line;
        while(std::getline(MyReadFile, line)){
            bookList.push_back(line);
        }
    }
}

//delete a book from vector
void deleteBook(std::vector<std::string>& bookList) {
    std::cout << "Book to delete: ";
    std::string target{};
    std::getline(std::cin, target);

    std::ifstream inFile("BookName.txt");
    std::vector<std::string> temp;
    bool found = false;

    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            if (line != target) {
                temp.push_back(line);
            } else {
                found = true;
            }
        }
        inFile.close();

        if (!found) {
            std::cout << "Book not found.\n";
            return;
        }

        std::ofstream outFile("BookName.txt", std::ios::trunc);
        for (const auto& book : temp) {
            outFile << book << "\n";
        }

        bookList = std::move(temp);
        std::cout << "Book deleted successfully.\n";
    } else {
        std::cout << "File not found\n";
    }
}

void searchItem(std::vector <std::string>& bookList){
    std::string query{};
    std::cout << "Search Item: ";
    std::getline(std::cin, query);

    bool found = false;

    for (size_t i = 0; i < bookList.size(); i++) {
        if (bookList[i].find(query) != std::string::npos) { // partial match
            std::cout << "Found: \"" << bookList[i] << "\" at index " << i << "\n";
            found = true;
        }
    }

    if(!found){
        std::cout << "No matches found\n";
    }
}

void editBookTitle(std::vector <std::string>& bookList){

    for (size_t i = 0; i < bookList.size(); i++){
        std::cout <<  i  << ": "  << bookList[i] << "\n";
    }

    std::string targetBook {};

    std::cout << "Book title to edit: ";
    std::getline(std::cin, targetBook);

    auto it = std::find(bookList.begin(), bookList.end(), targetBook);

    if(it != bookList.end()){
        std::string newTitle{};
        std::cout << "Enter new title: ";
        std::getline(std::cin, newTitle);

        *it = newTitle;

        std::ofstream WriteFile("BookName.txt");
        if(WriteFile.is_open()){
            for (const auto& book : bookList){
                WriteFile << book << "\n";
            }
            WriteFile.close();
            std::cout << "Book Updated in BookName.txt";
        }
        else{
            std::cout << "Error opening the file\n";
        }
    } else{
        std::cout << "Book not found\n";
    }


}
