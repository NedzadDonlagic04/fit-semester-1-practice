#include <iostream>
#include "./includes/mergeSort.hpp"

int main() {
    auto idk {recursiveMergeSort({9, 1, 5, 4, 2, 0}) };

    for (const auto &i : idk) std::cout<<i<<'\n';

    return 0;
}
