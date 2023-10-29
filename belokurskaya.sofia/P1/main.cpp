#include <iostream>
#include <limits>
#include <stdexcept>

const int Min = std::numeric_limits<int>::min();

struct SequenceCounter
{
  SequenceCounter():
   count_(0),
   max_(Min),
   count_max_(1)
  {}
  void count(int number)
  {
    size_t max_size = std::numeric_limits<size_t>::max();
    if (count_ == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
    if (number > max_)
    {
      max_ = number;
      count_max_ = 1;
    }
    else if (number == max_)
    {
      ++count_max_;
    }
    ++count_;
  }
  size_t get_result() const
  {
    return count_max_;
  }

private:
  size_t count_;
  int max_;
  size_t count_max_;
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
      std::cerr << " Is not a sequence\n";
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
  std::cout << counter.get_result()  << "\n";
}
