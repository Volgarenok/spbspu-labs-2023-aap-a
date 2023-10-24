#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <limits>
#include <cstddef>

class sequence
{
  size_t number_count = 0;
  long long number_min = std::numeric_limits<long long>::max();
  size_t max_length = std::numeric_limits<size_t>::max();

public:
  void doCount(long long num);
  void changeNum(long long num);
  void changeNum();
  int getRez();
};

#endif
