#include <iostream>
#include <limits>
#include <stdexcept>

namespace marishin
{
  class Sequence
  {
  public:
    void operator()(int num)
    {
      size_t max_size = std::numeric_limits< size_t >::max();
      if (global_count == max_size)
      {
        throw std::logic_error("sequence is too long");
      }
    }
    size_t operator()() const
    {
      return global_count;
    }
  }
}

int main()
{
  long long int num;
  std::cin >> num;
  if (!std::cin)
  {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  while (true)
  {
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    std::cin >> num;
  }
}
