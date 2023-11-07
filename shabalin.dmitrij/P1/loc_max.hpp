#ifndef LOC_MAX_HPP
#define LOC_MAX_HPP
#include <cstddef>
namespace shabalin
{
  class LocMax
  {
  public:
    LocMax();
    void operator()(long long Number);
    size_t operator()() const;
  private:
    size_t count_;
    long long m_firstNumber;
    long long m_secondNumber;
    long long m_thirdNumber;
  };
}
#endif
