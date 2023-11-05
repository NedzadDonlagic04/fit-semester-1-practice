#pragma once

#include <vector>

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

[[nodiscard]] std::vector<int> recursiveMergeSort(const std::vector<int> &arr, bool sortAscending=true);
void iterativeMergeSort(std::vector<int> &arr, bool sortAscending=true);

#endif 
