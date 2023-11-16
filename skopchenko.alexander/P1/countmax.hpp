#ifndef COUNTMAX_HPP
#define COUNTMAX_HPP

#include <cstddef>

namespace skopchenko
{
  struct CountMax
  {
  public:
    CountMax();
    void operator()(int current);
    size_t operator()() const;

  private:
    int max_;
    size_t count_;
  };
}
#endif
