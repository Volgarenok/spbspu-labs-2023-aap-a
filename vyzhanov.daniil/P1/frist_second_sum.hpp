#ifndef FIRST_SECOND_SUM_HPP
#define FIRST_SECOND_SUM_HPP

#include <cstddef>

namespace vyzhanov1
{
  struct Sum
  {
    Sum();
    void operator()(int num);
    size_t operator()() const;
  private:
   size_t count_all, count;
   int first, second, third;
  };
}
#endif
