#include "ismax.hpp"

void isMax(int now, int& actual, int& pre)
{
  if (now >= actual)
  {
    pre = actual;
    actual = now;
  }
  else if (now > pre)
  {
    pre = now;
  }
}
