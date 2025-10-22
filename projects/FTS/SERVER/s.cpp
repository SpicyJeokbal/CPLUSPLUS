

#include <iostream>
#include <fstream>
#include <vector>

std::vector<char> readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return {};
    }
    return std::vector<char>((std::istreambuf_iterator<char>(file)), {});
}

void writeFile(const std::string& filename, const std::vector<char>& data) {
    std::ofstream file(filename, std::ios::binary);
    file.write(data.data(), data.size());
}

int main() {
    std::string filename = "example.jpg"; 
    std::vector<char> data = readFile(filename);

    std::cout << "Read " << data.size() << " bytes from " << filename << std::endl;

    writeFile(filename, data);


    return 0;
}
