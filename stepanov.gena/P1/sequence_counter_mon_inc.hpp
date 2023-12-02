#ifndef SEQUENCE_COUNTER_MON_INC_HPP
#define SEQUENCE_COUNTER_MON_INC_HPP

#include <cstddef>

namespace stepanov
{
  struct SequenceCounterMonInc
  {
    SequenceCounterMonInc();
    void counter(size_t);
    size_t getResult() const;

  private:
    size_t last_number_;
    size_t current_count_;
    size_t max_count_;
  };
}

#endif
