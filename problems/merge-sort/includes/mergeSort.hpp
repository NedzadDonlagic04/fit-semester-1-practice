#pragma once

#include <vector>

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

void recursiveMergeSort(const std::vector<int> &arr, bool sortAscending=true);
void nonRecursiveMergeSort(const std::vector<int> &arr, bool sortAscending=true);

#endif 
