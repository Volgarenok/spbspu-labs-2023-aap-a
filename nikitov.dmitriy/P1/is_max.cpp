#include "is_max.hpp"

void nikitov::isMax(int now, int& actual, int& pre)
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
