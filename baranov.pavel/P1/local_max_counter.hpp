#ifndef LOCAL_MAX_COUNTER_HPP
#define LOCAL_MAX_COUNTER_HPP

#include <cstddef>
namespace baranov
{
class LocalMaxCounter
{
public:
  LocalMaxCounter(long long int firstNumber, long long int secondNumber);
  void count(long long int number);
  size_t get_result() const;
private:
  long long int prevNumber;
  long long int currentNumber;
  long long int nextNumber;
  size_t count_;
};
}

#endif

