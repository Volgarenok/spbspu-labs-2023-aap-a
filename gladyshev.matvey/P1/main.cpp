#include "countermain.h"

int main()
{
  using namespace gladyshev;
  long long int number = 1;
  unsigned long long counter = 0;
  Countermain itog;
  while (number != 0)
  {
    std::cin >> number;
    if (!std::cin)
    {
      return 1;
    }
    if (counter == 0 && number == 0)
    {
      std::cout << "is not a sequence\n";
    }
    ++counter;
    try
    {
      itog(number);
    }
    catch (const std::exception & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      return 2;
    }
  }
  std::cout << itog() << "\n";
}

