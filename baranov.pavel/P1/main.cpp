#include <iostream>

int main()
{
  long long int number = 0;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
  }
  while (number != 0);
}
