#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COIUNTER_HPP
#include <cstddef>

namespace stepanov
{
  struct SequenceCounter
  {
    SequenceCounter();
    void operator()(int number);
    size_t operator()() const;
private:
    size_t max_count;
    size_t count_;
    int last;
    size_t c;
  };
}
#endif
