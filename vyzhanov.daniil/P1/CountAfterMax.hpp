#ifndef COUNTERAFTERMAX_HPP
#define COUNTERAFTERMAX_HPP

#include <cstddef>

namespace vyzhanov
{
  struct CountAfterMax
  {
    CountAfterMax();
    void operator()(int num);
    size_t operator()() const;
  private:
    int maxi_num_;
    size_t after_max_;
  };
}
#endif
