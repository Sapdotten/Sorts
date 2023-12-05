#ifndef SRC_SORTS_SORTS_CC
#define SRC_SORTS_SORTS_CC
#include "../include/stats.h"
#include <vector>
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
    arr.at(j) = elem;
    stats.copy_count++;
  }
  return stats;
}



}
#endif