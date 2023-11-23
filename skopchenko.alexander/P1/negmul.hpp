#ifndef NEGMUL
#define NEGMUL

#include <cstddef>

namespace skopchenko
{

  struct Negmul
  {
  public:
    Negmul();
    void operator()(int current);
    size_t operator()() const;

  private:
    int prevNum_;
    int result_;
    size_t count_;
    size_t maximum_;
  };

}

#endif