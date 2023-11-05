#ifndef MONINC_HPP
#define MONINC_HPP
#include <cstddef>

namespace spiridonov
{
  class Moninc
  {
    public:
      Moninc();
      void operator()(int num);
      size_t operator()() const;

    private:
      size_t max_length_;
      size_t curr_length_;
      int prev_num_;
  };
}
#endif
