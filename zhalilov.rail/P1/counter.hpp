#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <cstddef>

namespace zhalilov
{
  class Counter
  {
    size_t count;
    size_t maxSeq;
  public:
    Counter();
    void operator()(int prev, int curr);
    size_t operator()() const;
  };
}
#endif
