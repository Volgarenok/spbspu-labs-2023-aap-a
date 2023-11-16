#include <iostream>
#include "cntmax.hpp"
#include "incseq.hpp"

int main()
{
  using namespace skopchenko;

  IncSeq countIncSeq;
  CntMax countCntMax;
  int current = 0;

  do
  {
    std::cin >> current;
    if (!std::cin)
    {
      std::cerr << "Bad input\n";
      return 1;
    }
    else if (current != 0)
    {
      try
      {
        countCntMax(current);
        countIncSeq(current);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error:" << e.what() << "\n";
        return 2;
      }
    }
  }
  while (current != 0);

  try
  {
    size_t incSeq = countIncSeq();
    size_t cntMax = countCntMax();
    std::cout << "[INC-SEQ]:" << incSeq << "\n";
    std::cout << "[CNT-MAX]:" << cntMax << "\n";
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error:" << e.what() << "\n";
    return 2;
  }

  return 0;
}
