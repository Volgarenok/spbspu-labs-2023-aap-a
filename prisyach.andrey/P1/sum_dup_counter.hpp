#ifndef SUM_DUP_COUNTER_HPP
#define SUM_DUP_COUNTER_HPP

#include <cstddef>

namespace prisyach
{
  struct SumDupCounter
  {
    SumDupCounter();
    void operator()(int num);
    size_t operator()() const;
  private:
    int number1_;
    int number2_;
    int number3_;
    unsigned int flag_;
    size_t count_;
  };
}

#endif
