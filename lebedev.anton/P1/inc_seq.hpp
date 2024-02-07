#ifndef INC_SEQ_HPP
#define INC_SEQ_HPP

#include <cstddef>
namespace lebedev
{
  struct IncSeqCounter
  {
    IncSeqCounter();
    void operator()(int curr_num);
    size_t operator()() const;
  private:
    size_t count_;
    int prev_num_;
  };
}
#endif
