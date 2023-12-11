#include "min.hpp"
#include <algorithm>

int chistyakov::min(int num1, int num2, int num3, int num4)
{
  int localMin = min(num1, num2, num3);
  return std::min(localMin, num4);
}

int chistyakov::min(int num1, int num2, int num3)
{
  int localMin = std::min(num1, num2);
  return std::min(localMin, num3);
}

