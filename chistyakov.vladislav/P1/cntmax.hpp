#ifndef CNTMAX_HPP
#define CNTMAX_HPP

#include <cstddef>

namespace chistyakov
{
  struct CntMax
  {
  public:
    CntMax();
    void operator()(int number);
    size_t operator()() const;

  private:
    int max_;
    size_t counter_;
  };
}
#endif
