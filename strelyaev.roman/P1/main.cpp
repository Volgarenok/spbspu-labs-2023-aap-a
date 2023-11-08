#include <iostream>
#include "mondec.h"

int main()
{
  using namespace strelyaev;
  int current_number = 0;
  Mondec count;
  do
  {
    std::cin >> current_number;
    if (!std::cin)
    {
      std::cerr << "AN ERROR HAS OCCURRED: NOT A NUMBER\n";
      return 1;
    }
    else if (current_number != 0)
    {
      try
      {
        count(current_number);
      }
      catch (const std::logic_error & e)
      {
        std::cerr << "ERROR: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (current_number != 0);
  std::cout << count() << "\n";
}
