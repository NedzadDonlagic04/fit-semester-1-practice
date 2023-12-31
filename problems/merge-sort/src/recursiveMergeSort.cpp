#include "./../includes/mergeSort.hpp"
#include <cstddef>
#include <iostream>

[[nodiscard]] std::vector<int> merge(std::vector<int> &leftVec, std::vector<int> &rightVec) {
  std::size_t leftIndex { 0 }, rightIndex { 0 };

  std::vector<int> returnVec (leftVec.size() + rightVec.size());

  while (leftIndex != leftVec.size() && rightIndex != rightVec.size()) {
    if (leftVec[leftIndex] < rightVec[rightIndex]) 
      returnVec[leftIndex + rightIndex] = leftVec[leftIndex++];
    else 
      returnVec[leftIndex + rightIndex] = rightVec[rightIndex++];
  }

  while (leftIndex != leftVec.size()) 
    returnVec[leftIndex + rightIndex] = leftVec[leftIndex++];

  while (rightIndex != rightVec.size())
    returnVec[leftIndex + rightIndex] = rightVec[rightIndex++];
  
  return returnVec;
}

[[nodiscard]] std::vector<int> recursiveMergeSort(const std::vector<int> &vec, bool isAscending) {
  if (vec.size() == 1) return vec;

  auto size { vec.size() };

  auto leftHalfVec { recursiveMergeSort(std::vector(&vec[0], &vec[size / 2])) };
  auto rightHalfVec { recursiveMergeSort(std::vector(&vec[size / 2], &vec[size])) };

  return merge(leftHalfVec, rightHalfVec); 
}
