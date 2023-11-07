#include "loc_max.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  long long Number = 0;
  long long m_firstNumber = 0;
  using namespace shabalin;

  LocMax counter;

  do
  {
    std::cin >> Number;
    if (!std::cin)
    {
      std::cerr << "is not sequence" << "\n";
      return 1;
    }
    if (Number != 0)
    {
      try
      {
        counter(Number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (Number != 0);
  std::cout << counter() << "\n";
}
