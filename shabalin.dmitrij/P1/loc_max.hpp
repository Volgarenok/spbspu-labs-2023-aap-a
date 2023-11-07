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
    size_t operator()() const;
    long long thirdNumber;
  private:
    size_t count_;
    long long firstNumber;
    long long secondNumber;
  };
}
#endif
