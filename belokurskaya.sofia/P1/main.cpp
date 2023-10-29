#include <iostream>

int main()
{
  int number = 0;
  size_t count = 0;
  int max = 0;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << " Is not a sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      if (number > max)
        {
          max = number;
          count = 1;
        }
        else if (number == max)
        {
          ++count;
        }
    }
  }
  while (number != 0);
  std::cout << count << "\n";
}
