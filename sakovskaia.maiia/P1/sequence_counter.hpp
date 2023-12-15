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
    int last_number_;
    size_t count_;
  };
}
#endif
