#include <iostream>
#include <fstream>

class FileManager{
    private:
        std::string FileName;
    public:

        FileManager(const std::string& fname){
            FileName = fname;
        }

        void WritetoFile(const std::string& content){
            std::ofstream file(FileName);
            if(file.is_open()){
                file << content;
                file.close();
                std::cout << "file written succesfully\n";
            }
            else{
                std::cout << "file not found";
            }
        }

        std::string ReadfromFile(){
            std::ifstream file(FileName);
            std::string line, alltext = ""; 

            if(file.is_open()){
                while(std::getline(file,line)){
                    alltext += line + "\n";
                }
                file.close();
            }else{
                std::cout << "File not found";
            }
            return alltext;
        }
};



int main(){

    FileManager myFile("sample.txt");

    myFile.WritetoFile("Wassup");

    std::cout << myFile.ReadfromFile();



    return 0;
}