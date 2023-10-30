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
    void count(int number);
    size_t get_result() const;
  private:
    size_t counts;
  };
}
#endif
