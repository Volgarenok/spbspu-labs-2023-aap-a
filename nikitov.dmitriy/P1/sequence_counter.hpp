#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>

struct SequenceCounter
{
  SequenceCounter();
  void isLimit(int);
  size_t check_count() const;
  private:
    size_t count_;
};

#endif
