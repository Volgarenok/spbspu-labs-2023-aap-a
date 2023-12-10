#ifndef NUMBEROFPYTHAGOR_HPP
#define NUMBEROFPYTHAGOR_HPP

#include <cstddef>
namespace agarkov
{
  struct NumberOfPythagor
  {
    NumberOfPythagor();
    void operator()(int current);
    size_t operator()() const;
  private:
    size_t triples_;
    int p_;
    int p_t_;
    bool isPythTriple(int current);
  };
}

#endif
