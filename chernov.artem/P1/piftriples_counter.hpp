#ifndef PIFTRIPLES_COUNTER_HPP
#define PIFTRIPLES_COUNTER_HPP
#include <cstddef>

namespace chernov
{
  struct PifTriplesCounter
  {
    PifTriplesCounter();
    void operator()(int number);
    size_t operator()() const;
  private:
    bool findPifTriples(int number);
    size_t piftriples_;
    int first_el_;
    int second_el_;
  };
}

#endif
