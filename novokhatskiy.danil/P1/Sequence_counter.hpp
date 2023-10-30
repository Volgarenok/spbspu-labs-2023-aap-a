#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>
namespace novokhatskiy
{
  struct SequenceCounterMax
  {
    SequenceCounterMax();
    void operator()(int num);
    size_t operator()() const;
  private:
    size_t count_;
    int max_;
  };
}
#endif
