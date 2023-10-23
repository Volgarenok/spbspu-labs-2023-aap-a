#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <cstddef>

namespace zhalilov
{
  class Counter
  {
    size_t m_count;
    size_t m_maxSeq;
  public:
    Counter();
    void operator()(int prev, int curr);
    size_t operator()() const;
  };
}
#endif
