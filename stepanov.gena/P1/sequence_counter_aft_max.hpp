#ifndef SEQUENCE_COUNTER_AFT_MAX_HPP
#define SEQUENCE_COUNTER_AFT_MAX_HPP

#include <cstddef>

namespace stepanov
{
  struct SequenceCounterAftMax
  {
    SequenceCounterAftMax();
    void counter(int);
    size_t getResult() const;

  private:
    int maxElement_;
    size_t countAfterMax_;
    size_t count_;
    size_t isFirst_;
  };
}
#endif
