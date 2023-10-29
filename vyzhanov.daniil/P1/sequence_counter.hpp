#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>

struct SequenceCounter
{
  SequenceCounter();
  void size(int num);
  size_t get_res() const;
private:
  size_t count;
};

#endif
