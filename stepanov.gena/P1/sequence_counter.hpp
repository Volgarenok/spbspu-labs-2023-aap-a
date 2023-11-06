#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COIUNTER_HPP
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
