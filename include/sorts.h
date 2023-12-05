#ifndef INCLUDE_SORTS_H
#define INCLUDE_SORTS_H
#include "stats.h"
#include <vector>

namespace Sorts {

Stats InsertSort(std::vector<int> &arr);
Stats QuickSort(std::vector<int> &arr);

}  // namespace Sorts
#endif