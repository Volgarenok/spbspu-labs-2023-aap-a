#ifndef NEGMUL.HPP
#define NEGMUL.HPP

namespace skopchenko
{

  Struct NegMul
  {
    public:
      NegMul();
      void operator()(int current);
      size_t operator()() const;

    private:
      size_t count_;
      int prev_;
      bool seqCheck;
  };
}

#endif
