#include <iostream>
#include <limits>

int main()
{
  size_t max_length = std::numeric_limits<size_t>::max();
  size_t number_count = 0;
  long long number_min = std::numeric_limits<long long>::max();
  long long  number_current = 0;
  do
  {
    std::cin >> number_current;
    if (!std::cin)
    {
      std::cerr << "Not a sequence\n";
      return 1;
    }
    if (number_current != 0)
    {
      if (number_count == max_length)
      {
        std::cout << "Sequence is too long\n";
        return 2;
      }
      if (number_current == number_min)
      {
        number_count += 1;
      }
      else if (number_current < number_min)
      {
        number_min = number_current;
        number_count = 1;
      }
    }
  }
  while (number_current != 0);
  std::cout << number_count << "\n";
}
