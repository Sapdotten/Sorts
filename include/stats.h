#ifndef INCLUDE_STATS_H
#define INCLUDE_STATS_H
namespace Sorts {

struct Stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
    Stats(int comp_count, int _copy_count)
        : comparison_count(comp_count), copy_count(_copy_count){};
    Stats() = default;
    Stats& operator+(const Stats& other);

    Stats& operator+=(const Stats& other);
  };

}

#endif