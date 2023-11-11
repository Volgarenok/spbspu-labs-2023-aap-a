#ifndef FIRST_SECOND_SUM_HPP
#define FIRST_SECOND_SUM_HPP

#include <cstddef>

namespace vyzhanov
{
  struct SumDup
  {
    SumDup();
    void operator()(int num);
    size_t operator()() const;
  private:
   size_t count_sum_;
   int num1_, num2_, num3_;
  };
}
#endif
