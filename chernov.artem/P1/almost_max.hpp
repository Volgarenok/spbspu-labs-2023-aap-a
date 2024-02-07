#ifndef ALMOST_MAX_HPP
#define ALMOST_MAX_HPP
#include <cstddef>

namespace chernov
{
  struct AlmostMax
  {
    AlmostMax();
    void operator()(int number);
    int operator()() const;
  private:
    int premax_;
    int max_;
  };
}

#endif
