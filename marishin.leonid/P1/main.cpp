#include <iostream>
#include "sequence.hpp"

int main()
{
  using namespace marishin;
  Sequence seq;
  long long int num;
  std::cin >> num;
  if (!std::cin)
  {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  while (num != 0)
  {
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    try
    {
      seq(num);
    }
    catch (const std::exception& e)
    {
      std::cerr << "ERROR: " << e.what() << "\n";
      return 2;
    }
    std::cin >> num;
  }
  if (seq.get_global_count() <= 2)
  {
    std::cerr << "Error: The sequence is too short\n";
    return 2;
  }
  std::cout << seq() << "\n";
}
