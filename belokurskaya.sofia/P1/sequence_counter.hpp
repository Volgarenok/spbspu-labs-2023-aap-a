#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>
namespace belokurskaya
{
  struct SequenceCounter
  {
    SequenceCounter();
    void operator()(int number);
    size_t operator()() const;
  private:
    size_t count_;
    int max_;
    size_t count_max_;
  };
}
#endif
