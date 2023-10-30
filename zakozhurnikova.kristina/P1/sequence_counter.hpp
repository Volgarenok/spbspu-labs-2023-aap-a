#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <limits>
#include <cstddef>
namespace zakozhurnikova
{
  struct SequenceCounter
  {
    int max = std::numeric_limits< int >::min();
    SequenceCounter();
    void operator()(int number);
    size_t operator()() const;
  private:
    size_t counts;
  };
}
#endif
