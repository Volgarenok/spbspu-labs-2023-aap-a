#include "chet_counter.hpp"

void chetCounter(int now, size_t& max, size_t& actual)
{
  if (now % 2 == 0)
  {
    ++actual;
    if (actual > max){
      max = actual;
    }
  }
  else
  {
    actual = 0;
  }
}
