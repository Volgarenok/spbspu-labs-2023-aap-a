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
      std::cerr << "Bad input, try again\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        counterCntMax(number);
        counterGrtLss(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);

  try
  {
    size_t answOne = counterCntMax();
    size_t answTwo = counterGrtLss();
    std::cout << "[CNT-MAX]: " << answOne << "\n";
    std::cout << "[GRT-LSS]: " << answTwo << "\n";
  }
  catch (const std::exception & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }

  return 0;
}
