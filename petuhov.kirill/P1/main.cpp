#include <iostream>
#include <limits>
#include <stdexcept>

struct SequenceEvenCounter {
  SequenceEvenCounter():
    temp_count(0),
    max_count(0)
  {}

  void count(int num)
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (temp_count == max_size)
    {
      throw std::logic_error("Sequence is too long");
    }
    if (num % 2 == 0)
    {
      ++temp_count;
      max_count = max_count < temp_count ? temp_count : max_count;
    }
    else
    {
      temp_count = 0;
    }
  }

  size_t getMax() const
  {
    return max_count;
  }

  private:
    size_t temp_count;
    size_t max_count;
};

int main()
{
  int num = 0;
  SequenceEvenCounter counter;

  while (true)
  {
    std::cin >> num;

    if (!std::cin)
    {
      std::cerr << "Input is not a valid number!" << std::endl;
      return 1;
    }

    if (num == 0)
    {
      break;
    }
    else
    {
      try
      {
        counter.count(num);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << std::endl;
        return 2;
      }
    }
  }

  std::cout << counter.getMax() << std::endl;
}
