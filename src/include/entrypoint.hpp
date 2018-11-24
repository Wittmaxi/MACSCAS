#pragma once

#include "codecache.hpp"
#include <algorithm>

CodeCache removeSpaces (CodeCache& code) {
    for (auto &i : code.codeLines)
        i.erase(std::remove_if(i.begin(), i.end(), isspace), i.end());
    return code;
}

struct context{};

bool handleControls (const std::string &line, context& cnt) {
    if (line == "---") {
        cnt = context ();
    }
}

void executeLinePerLine (CodeCache& code) {
    code = removeSpaces(code);
    context codeContext;
    for (const auto &i : code.codeLines) {
        if (!handleControls(i, codeContext)) {

        }
    }
}