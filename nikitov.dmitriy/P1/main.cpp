#include <iostream>
#include "sequence_counter.hpp"
#include "ismax.hpp"

int main()
{
  int number = 0;
  int actual_max = 0;
  int pre_max = 0;
  using namespace nikitov;
  SequenceCounter counter;

  do{
    std::cin >> number;
    if (!std::cin){
      std::cerr << "Error: This is not a sequence\n";
      return 1;
    }
    else if (number != 0){
      try
      {
        counter(number);
      } 
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << '\n';
        return 2;
      }
      isMax(number, actual_max, pre_max);
    }
  }
  while (number != 0);

  if (counter() == 0 || counter() == 1){
    std::cerr << "Error: This sequence is too short\n";
    return 2;
  }
  std::cout << pre_max << '\n';
  return 0;
}
