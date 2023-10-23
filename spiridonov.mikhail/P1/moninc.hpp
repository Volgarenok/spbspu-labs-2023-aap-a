#ifndef MONINC_HPP
#define MONINC_HPP
#include <cstddef>

namespace spiridonov // добавил пространство имён
{
  class Moninc
  {
    public:
      Moninc();
      void operator()(int num);
      void operator()();
      size_t output() const;

    private:
      size_t max_length;
      size_t curr_length;
      int prev_num;
  };
}
#endif
