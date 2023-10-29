#include <iostream>
#include <limits>
#include <stdexcept>

struct SequenceCounter
{
  SequenceCounter():
   counts(0)
  {}

  void count(int number)
  {
    int max = std::numeric_limits< int >::min();
    size_t max_size = std::numeric_limits< size_t >::max();
    if (counts == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
    else if (number > max)
    {
      counts = 0;
      max = number;
    }
    else
    {
      ++counts;
    }
  }
  size_t get_result() const
  {
    return counts;
  }
private:
  size_t counts;
};
int main ()
{
  int number = 0;
  SequenceCounter counter;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        counter.count(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);
  std::cout << counter.get_result() << "\n";
}
