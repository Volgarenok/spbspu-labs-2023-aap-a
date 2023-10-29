#include <iostream>
#include <limits>

int main()
{
  int num = 0;
  size_t size = 0;
  do
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "Is not a sequance\n";
      return 1;
    }
    else if (num != 0)
    {
      size_t max_s = std::numeric_limits< size_t >::max();
      if (size == max_s)
      {
        std::cerr << "Sequence is too long!\n";
        return 2;
      }
      ++size;
    }
  }
  while (num != 0);
  std::cout << size << "\n";
}
