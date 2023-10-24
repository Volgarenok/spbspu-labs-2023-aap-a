#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <cstddef>
namespace marishin
{
  class Sequence
  {
  public:
    Sequence();
    void operator()(int num);
    size_t operator()() const;
    size_t get_global_count() const;
  private:
    size_t global_count;
    long long int prev1;
    long long int prev2;
    size_t count;
  };
}
#endif
