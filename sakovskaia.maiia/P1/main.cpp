#include <iostream>
#include <limits>
#include <stdexcept>

struct SequenceCounter
{
  SequenceCounter():
    count_(0)
  {}

  void count(int num)
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (count_ == max_size)
    {
      throw std::logic_error("Sequence is too long");
    }
    ++count_;
  }
  size_t get_result() const
  {
    return count_;
  }
private:
  size_t count_;
};

int main()
{
  int number = 0;
  SequenceCounter counter;
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
