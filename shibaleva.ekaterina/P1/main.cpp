#include <iostream>
#include <limits>
int main()
{
  int number = 0;
  size_t count = 0;
  int last = 0;
  int  count2 = 0;
  int answer = 0;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      size_t max_size = std::numeric_limits< size_t >::max();
      if (count == max_size)
      {
        std::cerr << "Sequence is too long!\n";
        return 2;
      }
      ++count;
      if (count == 1)
      {
        last = number;
      }
      if (count >= 2 and last > number and number != 0)
      {
        ++count2;
        if (count2 == 2)
        {
          count2 = 0;
          ++answer;
        }
      }
    }
  }
  while (number != 0);
  if (number == 0 and count < 3)
  {
    std::cerr << "Sequence is too small!\n";
    return 2;
  }
  std::cout << " " << answer << "\n";
}
