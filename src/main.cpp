#include <iostream>
#include <vector>
#include "include/lib/commander.hpp"
#include "include/codecache.hpp"
#include "include/commandline.hpp"
#include "include/entrypoint.hpp"

int main (int argc, char** argv) {
    CMD::commander arguments(argc-1, argv+1);
    CodeCache code = getAllFiles(arguments); 
    if (isInteractiveMode(arguments)) {

    } else {
        executeLinePerLine (code);
    }
}