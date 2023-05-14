#include <iostream>
#include <vector>
#include <algorithm>
#include "String.h"

void Program(const std::vector<sychkov::String>& stringList) {
    std::vector<sychkov::String> temp(stringList);

    std::sort(std::begin(temp), std::end(temp), sychkov::CompareStrings);
    std::reverse(std::begin(temp), std::end(temp));

    for (const auto& str : temp) {
        std::cout << str.getData() << std::endl;
    }
}

int main() {
    std::vector<sychkov::String> stringList;
    stringList.emplace_back("a");
    stringList.emplace_back("C");
    stringList.emplace_back("B");
    stringList.emplace_back("d");

    Program(stringList);

    return 0;
}
