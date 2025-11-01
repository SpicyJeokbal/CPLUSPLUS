
#include <iostream>
#include <fstream>

class fileHandler{
    public:
        
        fileHandler(){
            file = fopen("data.txt", "w");
            std::cout << "File open\n";
        }

        ~fileHandler(){
            fclose(file);
            std::cout << "file closed\n";
        }

    private:
        FILE* file;

};


int main(){
    
    fileHandler f;
    return 0;
}