#ifndef SRC_SORTS_SORTS_CC
#define SRC_SORTS_SORTS_CC
#include <vector>

#include "../include/stats.h"
namespace Sorts {
Stats InsertSort(std::vector<int> &arr) {
  Stats stats;
  for (size_t i = 1; i < arr.size(); ++i) {
    int elem = arr.at(i);
    stats.copy_count++;
    size_t j = i;
    while (j > 0 && arr.at(j - 1) > elem) {
      arr.at(j) = arr.at(j - 1);
      --j;
      stats.comparison_count++;
      stats.copy_count++;
    }
    stats.comparison_count++;
    arr.at(j) = elem;
    stats.copy_count++;
  }
  return stats;
}

Stats _QuickSort(std::vector<int> &arr, int start_ind, int end) {
  if (start_ind >= end) return Stats(0, 0);
  Stats stats;
  size_t start = start_ind;
  int pivot = end;
  while (start < pivot) {
    if (arr.at(start) > arr.at(pivot)) {
      int tmp = arr.at(start);
      stats.copy_count++;
      for (size_t j = start + 1; j <= pivot; ++j) {
        arr.at(j - 1) = arr.at(j);
        stats.copy_count++;
      }
      arr.at(pivot) = tmp;
      stats.copy_count++;
      --pivot;
    } else
      ++start;
    stats.comparison_count++;
  }
  stats += _QuickSort(arr, start_ind, pivot - 1);
  stats += _QuickSort(arr, pivot + 1, end);
  return stats;
}

Stats QuickSort(std::vector<int> &arr) {
  return _QuickSort(arr, 0, arr.size() - 1);
}

int GetNextGap(int gap) { return int(gap / 1.3); }

Stats CombSort(std::vector<int> &arr) {
  Stats stats;
  int gap = arr.size();
  while (gap > 1) {
    gap = GetNextGap(gap);
    for (int i = 0; i < arr.size() - gap; ++i) {
      if (arr.at(i) > arr.at(i + gap)) {
        int tmp = arr.at(i);
        arr.at(i) = arr.at(i + gap);
        arr.at(i + gap) = tmp;
        stats.copy_count += 3;
      }
      stats.comparison_count++;
    }
  }
  return stats;
}

}  // namespace Sorts
#endif