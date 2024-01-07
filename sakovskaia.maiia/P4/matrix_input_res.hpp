#ifndef MATRIX_INPUT_ANS_HPP
#define MATRIX_INPUT_ANS_HPP
#include <cstddef>
#include <fstream>

namespace sakovskaia
{
  std::ofstream & printAnswer(std::ofstream & output, int * a, size_t b);
  struct answerCounter
  {
    answerCounter();
    void operator()(int *, int *, size_t);
    size_t index;
  };
}
#endif
