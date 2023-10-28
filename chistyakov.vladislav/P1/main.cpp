#include <iostream>
#include <stdexcept>
#include "sequencenumofmax.hpp"
#include "grtlss.hpp"

int main()
{
  
  using namespace mySpace;
  grt_lss counterGRT;
  SequenceNumOfMax counter;
  
  // 3 cin для построение минимальной последовательности
  size_t number = 0;
  std::cin >> number;
  if (!std::cin)
  {
    std::cerr << "Bad input, try again\n";
    return 1;
  }
  else if (number == 0)
  {
    std::cout << "Sequence is too short\n";
    return 2;
  }
  counterGRT.firstNumber(number);
  counter.start_max(number);
  std::cin >> number;
  if (!std::cin)
  {
    std::cerr << "Bad input, try again\n";
    return 1;
  }
  else if (number == 0)
  {
    std::cout << "Sequence is too short\n";
    return 2;
  }
  counter.count(number);
  counterGRT.middleNumber(number);
  std::cin >> number;
  if (!std::cin)
  {
    std::cerr << "Bad input, try again\n";
    return 1;
  }
  else if (number == 0)
  {
      std::cout << "Sequence is too short\n";
      return 2;
  }
  try
  {
    counter.count(number);
    counterGRT.countGRT(number);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 2;
  }
  
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
        counter.count(number);
        counterGRT.countGRT(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  } 
  while (number != 0);
  std::cout << "[CNT-MAX]: " << counter.get_result() << "\n";
  std::cout << "[GRT-LSS]: " << counterGRT.get_result_grt() << "\n";
  return 0;
}
