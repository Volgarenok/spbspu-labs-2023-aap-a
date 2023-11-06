#include <iostream>
#include "cntmax.hpp"
#include "grtlss.hpp"

int main()
{
  using namespace chistyakov;

  GrtLss counterGrtLss;
  CntMax counterCntMax;
  int number = -1;

  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Bad input, try again";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        counterGrtLss(number);
        counterCntMax(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what();
        return 2;
      }
    }
  }
  while (number != 0);

  std::cout << "[CNT-MAX]: " << counterCntMax() << "\n";
  std::cout << "[GRT-LSS]: " << counterGrtLss() << "\n";
  return 0;
}
