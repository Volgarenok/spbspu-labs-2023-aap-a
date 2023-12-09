#ifndef COUNTEQUALSUMTWOPREV_HPP
#define COUNTEQUALSUMTWOPREV_HPP

#include <cstddef>

namespace vyzhanov
{
  struct CountEqualSumTwoPrev
  {
    CountEqualSumTwoPrev();
    void operator()(int num);
    size_t operator()() const;
  private:
    size_t count_sum_;
    int num1_, num2_, num3_;
  };
}
#endif
