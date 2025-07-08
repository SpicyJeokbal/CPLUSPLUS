#include <iostream>
#include <string>
using namespace std;

int main(){

    int n;
    cin >> n;
    string output = "";

    for(int i = 1; i <=n; i++){
        string word;
        cin >> word;
        if(word.size() > 10){
            word = word[0] + to_string (word.size() - 2) + word[word.size() - 1];
        }
        output += word + "\n";
    }

    std::cout << output << std::endl;

}