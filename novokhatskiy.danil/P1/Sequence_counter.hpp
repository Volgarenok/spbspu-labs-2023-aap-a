#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>
struct SequenceCounter
{
  SequenceCounter();
  void count(int);
  size_t get_result() const;
private:
  size_t count_;
};

#endif
