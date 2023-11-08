#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>
namespace sakovskaia
{
  struct SequenceSignsCounter
  {
    SequenceSignsCounter();
    void operator()(int);
    size_t operator()() const;
  private:
    size_t size = 0;
    int lastNumber = 0;
    size_t count_;
  };
}
#endif
