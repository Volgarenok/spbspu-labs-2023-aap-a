#ifndef AFT_MAX_HPP
#define AFT_MAX_HPP
#include <cstddef>
#include <iostream>
#include <limits>

namespace vojuck
{
  struct counterAftMax
  {
    counterAftMax();
    void operator()(int number, int &maxElement);
    size_t operator()() const;
  private:
    size_t count_;
  };
}
#endif
