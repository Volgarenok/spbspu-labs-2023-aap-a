#include <iostream>
#include "Sequence_counter.hpp"
#include <stdexcept>

struct SequenceCounter
{
  SequenceCounter():
   count_(0)
  {}
  void count(int num, size_t max)
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (count_ == max_size)
    {
      throw std::logic_error("Sequence is too long");
     }
     else if (num > max)
     {
	max = num;
        count_ = 0;
     }
     else
     {
       ++count_;
     }


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
  SequenceCounter counter;
  size_t count = 0;
  int num = 0;
  size_t max = 0;
  std::cin >> num;
  if (!std::cin)
  {
    std::cerr << "It is not a number\n";
    return 1;
  }
  while (num != 0)
  {
    if (num > max )
    {
      max = num;
      count = 0;
    }
    else
    {
      ++count;
     }

    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "It is not a number\n";
      return 1;
    }
    else if (num != 0)
    {
      try
      {
        counter.count(num,max);
      }
      catch (const std::exception& e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }

    }
  }
  std::cout << counter.get_result() << "\n";
  return 0;
}

