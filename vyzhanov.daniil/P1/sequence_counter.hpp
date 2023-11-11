#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>

namespace vyzhanov
{
  struct CountAfterMax
  {
    CountAfterMax();
    void operator()(int num);
    size_t operator()() const;
  private:
   int  maxi_num_, after_max_;
  };
}
#endif
