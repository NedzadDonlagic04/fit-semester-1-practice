#include <iostream>
#include "./includes/mergeSort.hpp"

int main() {
    std::vector<int> idk { 5, 8000, 324, 3260, 3212, 1 };

    iterativeMergeSort(idk);

    for (const auto &i : idk) std::cout<<i<<'\n';

    return 0;
}
