#include "./../includes/mergeSort.hpp"
#include <cstddef>
#include <iostream>

[[nodiscard]] std::vector<int> merge(std::vector<int> &leftVec, std::vector<int> &rightVec) {
  std::size_t leftIndex { 0 }, rightIndex { 0 };

  std::vector<int> returnVec (leftVec.size() + rightVec.size());

  while (leftIndex != leftVec.size() && rightIndex != rightVec.size()) {
    if (leftVec[leftIndex] < rightVec[rightIndex]) {
      returnVec[leftIndex + rightIndex] = leftVec[leftIndex];
      leftIndex++;
    } else {
      returnVec[leftIndex + rightIndex] = rightVec[rightIndex];
      rightIndex++;
    }
  }

  while (leftIndex != leftVec.size()) {
      returnVec[leftIndex + rightIndex] = leftVec[leftIndex];
      leftIndex++;
  }

  while (rightIndex != rightVec.size()) {
      returnVec[leftIndex + rightIndex] = rightVec[rightIndex];
      rightIndex++;
  }
  
  return returnVec;
}

[[nodiscard]] std::vector<int> recursiveMergeSort(const std::vector<int> &vec, bool isAscending) {
  if (vec.size() == 1) return vec;

  auto size { vec.size() };

  auto leftHalfVec { recursiveMergeSort(std::vector(&vec[0], &vec[size / 2])) };
  auto rightHalfVec { recursiveMergeSort(std::vector(&vec[size / 2], &vec[size])) };

  return merge(leftHalfVec, rightHalfVec); 
}

[[nodiscard]] std::vector<int> nonRecursiveMergeSort(const std::vector<int> &vec, bool isAscending) {
  for (std::size_t i = 2; i < vec.size(); i *= 2) {
    for (std::size_t ii = 0; ii < vec.size(); ii += i) {
      std::size_t middleVec { ii + i }, endVec { std::min(ii + i * 2 - 1, vec.size()) };

    }
  }

  return vec;
}
