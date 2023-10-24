#include <iostream>
#include <limits>
#include <stdexcept>

namespace marishin
{
  class Sequence
  {
    long long int prev1;
    long long int prev2;
  public:
    unsigned int count;
    unsigned int global_count;
    Sequence()
    {
      prev1 = 0;
      prev2 = 0;
      count = 0;
      global_count = 1;
    }
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
  marishin::Sequence seq;
  long long int num;
  Sequence seq;
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
    else if (num != 0)
    {
      try
      {
        seq(num);
      }
      catch (const std::exception& e)
      {
        std::cerr << "ERROR: " << e.what() << "\n";
        return 2;
      }
    }
    std::cin >> num;
  }
  if (seq.global_count <= 2)
  {
    std::cerr << "Error: The sequence is too short\n";
    return 2;
  }
  std::cout << seq() << "\n";
}
