#ifndef CNTMAX_HPP
#define CNTMAX_HPP

#include <cstddef>

namespace skopchenko
{
  struct CntMax
  {
  public:
    CntMax();
    void operator()(int current);
    size_t operator()() const;

  private:
    int max_;
    size_t count_;
  };
}
#endif
