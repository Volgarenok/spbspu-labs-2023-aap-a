#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>

namespace vyzhanov
{
  struct SequenceCounter
  {
    SequenceCounter();
    void operator()(int num);
    size_t operator()() const;
  private:
   size_t count;
   int  maxi_num, after_max;
  };
}
#endif
