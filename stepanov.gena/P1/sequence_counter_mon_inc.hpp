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
    size_t lastNumber_;
    size_t currentCount_;
    size_t maxCount_;
  };
}

#endif
