#ifndef FIRST_SECOND_SUM_HPP
#define FIRST_SECOND_SUM_HPP

#include <cstddef>

namespace vyzhanov
{
  struct First_Second_Sum
  {
    First_Second_Sum();
    void operator()(int num);
    size_t operator()() const;
  private:
    size_t count_sum_;
    int num1_, num2_, num3_;
  };
}
#endif
