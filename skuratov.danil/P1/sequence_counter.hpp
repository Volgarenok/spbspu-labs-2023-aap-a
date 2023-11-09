#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>
namespace skuratov
{
  struct MaxCounter
  {
    MaxCounter();
    void operator()(int);
    size_t operator()() const;
  private:
    int max_number_;
    size_t count_;
  };
}

#endif
