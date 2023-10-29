#include <iostream>
#include "mondec.hpp"

int main()
{
  long long int num = 1;
  using namespace piyavkin;
  MonDec mondec;
  while (num != 0)
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "error: This is not a sequence\n";
      return 1;
    }
    try
    {
      mondec(num);
    }
    catch (const std::exception& e)
    {
      std::cerr << "error: " << e.what() << "\n";
      return 2;
    }
  }
  std::cout << mondec() << "\n";
}
