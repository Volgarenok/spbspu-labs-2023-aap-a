#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>
namespace sakovskaia
{
  struct SequenceSignsCounter
  {
    SequenceSignsCounter();
    void operator()(size_t, int);
    void operator()(int, int);
    size_t operator()() const;
  private:
    size_t count_;
  };
}
#endif
