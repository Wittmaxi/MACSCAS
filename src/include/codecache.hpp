#pragma once

#include <vector>
#include <string>
#include <fstream>

struct CodeCache {
    std::vector <std::string> codeLines;
    int position = 0;
};

std::vector<std::string> readFile (std::ifstream& file) {
    std::vector<std::string> temp;
    std::string tempString;

    while (! file.eof()) {
        std::getline(file, tempString);
        temp.push_back(tempString);        
    }

    return temp;
}

std::vector<std::string> getCacheFromFile (const std::string& fileName) {
    std::ifstream file (fileName);

    if (! file.good())
        throw "File " + fileName + " not found!";
    
    return readFile(file);
}
