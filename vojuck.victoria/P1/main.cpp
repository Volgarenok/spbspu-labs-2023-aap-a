#include "aftmax.hpp"
#include "samemin.hpp"

int main()
{
  using namespace vojuck;
  counterAftMax aftMaxCounter;
  counterSameMin sameMinCounter;
  int number = 0;
  int min_int = std::numeric_limits< int >::min();
  int maxElement = min_int;
  int max_int = std::numeric_limits< int >::max();
  int minElement = max_int;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        aftMaxCounter(number, maxElement);
        sameMinCounter(number, minElement);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  } while (number != 0);
  std::cout << "AftMax counter: " << aftMaxCounter() << " SameMin counter: " << sameMinCounter() << "\n";
}
