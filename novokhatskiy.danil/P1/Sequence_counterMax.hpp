#ifndef SEQUENCE_COUNTERMAX_HPP
#define SEQUENCE_COUNTERMAX_HPP

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
