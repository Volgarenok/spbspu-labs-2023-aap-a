#ifndef PREVMORENEXTLESSCHECK_HPP
#define PREVMORENEXTLESSCHECK_HPP

#include <cstddef>

namespace vyzhanov
{
  struct MoreAndLess
  {
    MoreAndLess();
    void operator()(int num);
    size_t operator()() const;
  private:
    int next_num_, prev_num_, now_num_;
    size_t count_;
  };
}
#endif
