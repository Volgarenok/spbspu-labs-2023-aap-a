#include <iostream>

int main()
{
  long long int prevNumber = 1;
  long long int currentNumber = 1;
  long long int nextNumber = 1;

  std::cin >> prevNumber;
  if (!std::cin)
  {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  else if (prevNumber == 0)
  {
    std::cerr << "A sequence is too short \n";
    return 2;
  }

  std::cin >> currentNumber;
  if (!std::cin)
  {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  else if (currentNumber == 0)
  {
    std::cout << 0 << '\n';
    return 0;
  }

  do
  {
    std::cin >> nextNumber;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
  }
  while (nextNumber != 0);
}
