#ifndef LOC_MAX_HPP
#define LOC_MAX_HPP
#include <cstddef>
namespace shabalin
{
  class LocMax
  {
  public:
    LocMax(signed long long behindInt,signed long long curInt,signed long long nextInt);
    void operator()(signed long long Number);
    size_t operator()() const;
  private:
    size_t count_;
    signed long long firstNumber;
    signed long long secondNumber;
    signed long long thirdNumber;
  };
}
#endif
