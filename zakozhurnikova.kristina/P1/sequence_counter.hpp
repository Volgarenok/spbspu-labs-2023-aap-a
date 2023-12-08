#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <limits>
#include <cstddef>
namespace zakozhurnikova
{
  struct SequenceAfterMaximum
  {
    SequenceAfterMaximum();
    void operator()(int number);
    size_t operator()() const;
  private:
    size_t count_;
    int max_;
  };
}
#endif
