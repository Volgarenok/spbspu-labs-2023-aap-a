#ifndef AFT_MAX_HPP
#define AFT_MAX_HPP
#include <cstddef>

namespace vojuck
{
  struct CounterAftMax
  {
    CounterAftMax();
    void operator()(int number);
    size_t operator()() const;
  private:
    size_t count_;
    int maxElement_;
  };
}
#endif
