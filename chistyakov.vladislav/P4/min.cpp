#include "min.hpp"

int min(int num1, int num2, int num3)
{
  int localMin = (num1 < num2) ? num1 : num2;
  return (localMin < num3) ? localMin : num3;
}

int min(int num1, int num2, int num3, int num4)
{
  int localMin1 = (num1 < num2) ? num1 : num2;
  int localMin2 = (num3 < num4) ? num3 : num4;
  return (localMin1 < localMin2) ? localMin1 : localMin2;
}
