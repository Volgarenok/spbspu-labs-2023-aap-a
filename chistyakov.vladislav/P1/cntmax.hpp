#ifndef CNTMAX_HPP
#define CNTMAX_HPP

#include <cstddef>
#include <cstdint>

namespace chistyakov
{
  struct CntMax
  {
  public:
    CntMax();
    void operator()(intmax_t number);
    size_t operator()() const;

  private:
    intmax_t max_;
    size_t counter_;
  };
}
#endif
