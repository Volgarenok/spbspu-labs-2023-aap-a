#ifndef MORE_LESS_CHECK_HPP
#define MORE_LESS_CHECK_HPP

#include <cstddef>

namespace vyzhanov
{
  struct MoreAndLess
  {
    MoreAndLess();
    void operator()(int num);
    size_t operator()() const;
  private:
    int next_num, prev_num, now_num;
    size_t count;
  };
}
#endif
