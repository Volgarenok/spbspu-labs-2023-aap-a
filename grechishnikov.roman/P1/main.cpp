#include <iostream>
#include <limits>

int main()
{
  size_t number_count = 0;
  long long number_min = std::numeric_limits<long long>::max();
  int number_current = 0;
  do
  {
    std::cin >> number_current;
    if (!std::cin)
    {
      std::cerr << "Not a sequense\n";
      return 1;
    }
    if (number_current != 0)
    {
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
