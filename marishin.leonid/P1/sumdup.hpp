#ifndef SUMDUP_HPP
#define SUMDUP_HPP

#include <cstddef>
namespace marishin
{
  class SumDup
  {
  public:
    SumDup();
    void operator()(long long int num);
    size_t operator()() const;
  private:
    long long int prev1_;
    long long int prev2_;
    long long int prev3_;
    size_t count_;
  };
}
#endif
