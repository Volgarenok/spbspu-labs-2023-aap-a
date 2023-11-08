#include <iostream>
#include <limits>


void countSignChanges(int &previousNumber, int &currentNumber, size_t &counter)
{
  if ((currentNumber > 0 && previousNumber < 0) || (currentNumber < 0 && previousNumber > 0))
  {
    counter++;
  }

  previousNumber = currentNumber;
}

int main()
{
  int number = 0;
  size_t size = 0;

  size_t signChangeCounter = 0;
  int previousNumber = 0;

  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "sequence is not valid";
      return 1;
    }

    if (number != 0)
    {
      size_t max_size = std::numeric_limits<size_t>::max();
      if (size == max_size)
      {
        std::cerr << "sequence is too long";
        return 2;
      }
      size++;
    
      countSignChanges(previousNumber, number, signChangeCounter);
    }
  }
  while (number != 0);

  std::cout << signChangeCounter << '\n';

  return 0;
}

