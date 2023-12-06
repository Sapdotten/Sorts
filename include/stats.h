#ifndef INCLUDE_STATS_H
#define INCLUDE_STATS_H
#include <vector>
#include <ctime>
namespace Sorts {

struct Stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
    Stats(int comp_count, int _copy_count)
        : comparison_count(comp_count), copy_count(_copy_count){};
    Stats() : comparison_count(0), copy_count(0){};
    Stats& operator+(const Stats& other);

    Stats& operator+=(const Stats& other);
    Stats& operator/(int num);
    Stats& operator/=(int num);
  };

class MyVector {
    size_t seed;

 public:
    std::vector<int> GetRandomVector(int array_length);
    MyVector() : seed(std::time(NULL)){};

};

}

#endif