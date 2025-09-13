#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#pragma 



class searchEngine {
    public:
        struct Database{
            std::string Title;
            std::string Author;
            int year;
            std::string genre;
        };

        void addRecord(const Database& db){
            records.push_back(db);
        }

        std::string toLower(const std::string& str){
            std::string lower = str;
            std::transform(lower.begin(), lower.end(), lower.begin(),[](unsigned char c){return std::tolower(c); });
            return lower;
        }

        //partial match, case insensitive
        void searchItem(){
            std::string query{};
            std::cout << "Search Item: ";
            std::getline(std::cin, query);

            query = toLower(query);

            bool found = false;

            for(size_t i = 0; i < records.size(); i++){
                if(records[i].Title.find(query) != std::string::npos ||
                   records[i].Author.find(query) != std::string::npos ||
                   records[i].genre.find(query) != std::string::npos)
                    {
                    
                        std::cout << records[i].Title << " by " << records[i].Author << " (" << records[i].year << ") \n";
                        found = true;

                    }
            }
            if(!found){
                std::cout << "Book not found\n";
            }
        }

        
        void displayRecords(){
            if(records.empty()){std::cout<< "No books\n";}
            else{
                for(const auto r : records){
                    std::cout << r.Title << " by " << r.Author << " (" << r.year << ")- " << r.genre << "\n";
                }
            }
        }

        void deleteBook(){
            std::string query{};
            std::cout << "Item to delete: ";
            std::getline(std::cin, query);

            query = toLower(query);

            bool found = false;

            for(auto it = records.begin(); it < records.end();){
                if(toLower(it->Title).find(query) != std::string::npos )
                {
                    std::cout << "Deleting " << it->Title << " by " << it->Author << "\n";
                    it = records.erase(it);
                    found = true;
                } 
                else{
                    ++it;
                }
            }
            if(!found){
                std::cout << "Book not found\n";
            }
        }

    private:
        std::vector <Database> records;

};