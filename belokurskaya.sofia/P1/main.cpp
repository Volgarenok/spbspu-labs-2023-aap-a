#include <iostream>
#include<limits>

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
          size_t max_size = std::numeric_limits< size_t >::max();
          if (count == max_size)
          {
            std::cerr << "Sequence is too long\n";
            return 2;
          }
          ++count;
        }
    }
  }
  while (number != 0);
  std::cout << count << "\n";
}
