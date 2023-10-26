#ifndef SEQUENCENUMOFMAX_HPP
#define SEQUENCENUMOFMAX_HPP

#include <cstddef>
struct SequenceNumOfMax
{
  SequenceNumOfMax();
  void start_max(size_t nowNum);
  void count(size_t nowNum);
  size_t get_result() const;

private:
  size_t counter;
  size_t maxNum;
  size_t nowNum;
};

#endif
