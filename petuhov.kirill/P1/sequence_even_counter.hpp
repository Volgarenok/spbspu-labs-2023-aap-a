#ifndef SEQUENCE_EVEN_COUNTER_HPP
#define SEQUENCE_EVEN_COUNTER_HPP

#include <cstddef>

namespace petuhov
{
  struct SequenceEvenCounter
  {
    SequenceEvenCounter();
    void operator()(int num);
    size_t operator()() const;

    private:
      size_t temp_count_;
      size_t max_count_;
  };
}
#endif
