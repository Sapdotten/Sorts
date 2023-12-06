#ifndef INCLUDE_STATS_CC
#define INCLUDE_STATS_CC
#include "../include/stats.h"
#include <random>
#include <ctime>
#include "../include/sorts.h"
#include <iostream>
namespace Sorts {

  Stats& Stats::operator+(const Stats& other) {
    comparison_count += other.comparison_count;
    copy_count += other.copy_count;
    return *this;
  }

  Stats& Stats::operator+=(const Stats& other) { return this->operator+(other); }
  Stats& Stats::operator/(int num){ 
    comparison_count /= num;
    copy_count /= num;
    return *this;
  };
  Stats& Stats::operator/=(int num) { return this->operator/(num); };



  std::vector<int> MyVector::GetRandomVector(const int array_length){
    std::srand(seed);
    std::vector<int> arr(array_length);
    for (int i = 0; i < array_length; ++i) {
      arr.at(i) = rand() % array_length;
    }
    return arr;
  }
  

  }  // namespace Sorts

#endif