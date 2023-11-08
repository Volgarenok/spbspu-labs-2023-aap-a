#ifndef SEQUENCE_COUNTER_HPP
#define SEQUENCE_COUNTER_HPP

#include <cstddef>
namespace skuratov
{
  struct MaxCounter
  {
  public:
    MaxCounter();
    void operator()(int);
    size_t operator()() const;
    int max_number_ = 0;
  private:
    int number_;
    size_t count_;
  };
}

#endif
