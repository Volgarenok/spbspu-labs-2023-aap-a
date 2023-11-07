#ifndef LOC_MAX_HPP
#define LOC_MAX_HPP
#include <cstddef>
namespace shabalin
{
  class LocMax
  {
  public:
    LocMax(long long behindInt,long long curInt,long long nextInt);
    void operator()(signed long long Number);
    long long operator()() const;
  private:
    long long count_;
    long long firstNumber;
    long long secondNumber;
    long long thirdNumber;
  };
}
#endif
