#ifndef NEGMUL_HPP
#define NEGMUL_HPP

#include <cstddef>

namespace skopchenko
{

  struct NegMul
  {
  public:
    NegMul();
    void operator()(int current);
    int operator()() const;

  private:
    size_t count_;
    size_t maximum_;
    int result_;
    int maxResult_;
  };

}

#endif
