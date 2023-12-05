#ifndef INCLUDE_STATS_CC
#define INCLUDE_STATS_CC
#include "../include/stats.h"
namespace Sorts {

  Stats& Stats::operator+(const Stats& other) {
    comparison_count += other.comparison_count;
    copy_count += other.copy_count;
    return *this;
  }

  Stats& Stats::operator+=(const Stats& other) { return this->operator+(other); }

  }  // namespace Sorts

#endif