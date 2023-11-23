#ifndef NEGMUL
#define NEGMUL

#include <cstddef>

namespace skopchenko
{

  struct NegMul
  {
  public:
    NegMul();
    void operator()(int current);
    int operator()() const;

  private:
    int result_;
    int maxresult_;
    size_t count_;
    size_t maximum_;
  };

}

#endif
