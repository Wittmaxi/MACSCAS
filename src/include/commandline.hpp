#pragma once

#include "lib/commander.hpp"
#include <regex>

std::vector <std::string> getFileNames (const CMD::commander &arg) {
    return arg.getAllFlagsUnlike(std::regex ("-\\w*"));
}

std::vector<std::string> getAllFilesAsVector (const CMD::commander& arg) {
    std::vector<std::string> ret;
    for (const auto& i : getFileNames(arg)) {
        std::vector<std::string> temp = getCacheFromFile(i);
        ret.insert(ret.end(), temp.begin(), temp.end());
    }
    return ret;
}

CodeCache getAllFiles (const CMD::commander &arg) {
    CodeCache temp;
    temp.codeLines = getAllFilesAsVector(arg);
    temp.position = 0;
    return temp;
}

bool isInteractiveMode (const CMD::commander &arg) {
    return (arg.isFlagSet("-interactive") || arg.isFlagSet("-i"));
}