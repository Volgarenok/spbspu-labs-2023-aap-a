#include <iostream>
#include "submax_checker.hpp"
#include "even_nums_counter.hpp"

int main()
{
  long long int number = 0;
  using namespace nikitov;
  SubmaxChecker subChecker;
  EvenNumsCounter evenCounter;

  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Error: This is not a sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        subChecker(number);
        evenCounter(number);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error: " << e.what() << '\n';
        return 2;
      }
    }
  }
  while (number != 0);

  try
  {
    std::cout << subChecker() << '\n';
    std::cout << evenCounter() << '\n';
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 2;
  }
  return 0;
}
