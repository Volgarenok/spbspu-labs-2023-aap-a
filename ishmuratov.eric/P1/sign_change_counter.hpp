#ifndef SIGNCHANGE_COUNTER_HPP
#define SIGNCHANGE_COUNTER_HPP

#include <cstddef>

namespace ishmuratov
{
  struct SignChangeCounter
  {
    SignChangeCounter();
    void operator()(long long int num);
    size_t operator()() const;
  private:
    size_t change_count_;
    long long int prev_num_;
    long long int cur_num_;
  };
}

#endif
