#ifndef SUMDUP_COUNTER_HPP
#define SUMDUP_COUNTER_HPP

#include <cstddef>

namespace ishmuratov
{
  struct SumDupCounter
  {
    SumDupCounter();
    void operator()(long long int num);
    size_t operator()() const;
  private:
    size_t sum_count_;
    long long int first_num_;
    long long int second_num_;
    long long int cur_num_;
  };
}

#endif
