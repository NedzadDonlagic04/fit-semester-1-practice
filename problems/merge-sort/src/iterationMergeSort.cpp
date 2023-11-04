#include "./../includes/mergeSort.hpp"
#include <cstddef>
#include <iostream>

void merge() {

}

void iterativeMergeSort(std::vector<int> &vec, bool isAscending) {
  for (std::size_t i = 2; i < vec.size(); i *= 2) {
    for (std::size_t ii = 0; ii < vec.size(); ii += i) {
      std::size_t middleVec { ii + i }, endVec { std::min(ii + i * 2 - 1, vec.size()) };

    }
  }
}
