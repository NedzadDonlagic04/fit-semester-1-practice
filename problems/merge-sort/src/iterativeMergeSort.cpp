#include "./../includes/mergeSort.hpp"
#include <cstddef>
#include <cmath>
#include <iostream>

void merge(std::vector<int> &vec, std::size_t vecStart, const std::vector<int> &leftVec, const std::vector<int> &rightVec) {
  std::size_t leftIndex { 0 }, rightIndex { 0 };

  while (leftIndex != leftVec.size() && rightIndex != rightVec.size()) {
    if (leftVec[leftIndex] < rightVec[rightIndex]) 
      vec[vecStart++] = leftVec[leftIndex++];
    else 
      vec[vecStart++] = rightVec[rightIndex++];
  }

  while (leftIndex != leftVec.size())
    vec[vecStart++] = leftVec[leftIndex++];

  while (rightIndex != rightVec.size())
    vec[vecStart++] = rightVec[rightIndex++];
}

[[nodiscard]] std::vector<int> spliceVector(const std::vector<int> &vec, std::size_t start, std::size_t end) {
  std::vector<int> returnVal {};

  for(; start < end; start++) 
    returnVal.push_back(vec[start]);

  return returnVal;
}

void iterativeMergeSort(std::vector<int> &vec, bool isAscending) {
  for (std::size_t i = 1; i < vec.size(); i *= 2) {
    for (std::size_t start = 0; start < vec.size() - i; start += 2*i) {
      std::size_t mid { start + i }, end { std::min(mid + i, vec.size()) };

      auto leftArr { spliceVector(vec, start, mid) }, rightArr { spliceVector(vec, mid, end) };

      merge(vec, start, leftArr, rightArr);
    }
  }
}
