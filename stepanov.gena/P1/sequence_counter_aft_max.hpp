#ifndef SEQUENCE_COUNTER_AFT_MAX_HPP
#define SEQUENCE_COUNTER_AFT_MAX_HPP

#include <cstddef>

namespace stepanov
{
  struct SequenceCounterAftMax
  {
    SequenceCounterAftMax();
    void counter(int);
    size_t get_result() const;

  private:
    int maxElement_;
    size_t countAfterMax_;
    const size_t max_size_;
    size_t count_;
  };
}
#endif
