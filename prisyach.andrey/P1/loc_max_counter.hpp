#ifndef LOC_MAX_COUNTER_HPP
#define LOC_MAX_COUNTER_HPP

#include <cstddef>
namespace prisyach
{
  struct LocMaxCounter
  {
    LocMaxCounter();
    void operator()(int num);
    size_t operator()() const;
  private:
    int number1_;
    int number2_;
    int number3_;
    unsigned int flag_;
    size_t count_;
  };
}

#endif
