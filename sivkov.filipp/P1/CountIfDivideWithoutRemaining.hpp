#ifndef COUNTIFDIVIDEWITHOUTREMAINING_HPP
#define COUNTIFDIVIDEWITHOUTREMAINING_HPP
#include <cstddef>
namespace sivkov
{
  struct CountIfDivideWithoutRemaining
  {
    CountIfDivideWithoutRemaining();
    void operator()(int num);
    size_t operator()() const;
  private:
    size_t k_;
    int num_;
    int num_old_;
  };
}
#endif

