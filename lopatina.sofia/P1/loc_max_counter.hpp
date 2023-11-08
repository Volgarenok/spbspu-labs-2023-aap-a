#ifndef LOC_MAX_COUNTER_HPP
#define LOC_MAX_COUNTER_HPP

#include <cstddef>
namespace lopatina
{
  struct Loc_Max_Counter {
    Loc_Max_Counter();
    void operator()(int);
    size_t operator()() const;
  private:
    size_t count_;
  };
}

#endif
