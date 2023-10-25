#include <iostream>
#include <limits>
#include <stdexcept>

struct SequenceNumOfMax
{
  SequenceNumOfMax():
    counter(0)
  {}

  void start_max(size_t nowNum)
  {
    maxNum = nowNum;
    counter = 1;
  }

  void count(size_t nowNum)
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (counter == max_size)
    {
      throw std::logic_error("sequence is too long\n");
    }
    else if (maxNum == max_size)
    {
      throw std::logic_error("max numder is too big\n");
    }
    else if (nowNum == max_size)
    {
      throw std::logic_error("input numder is too big\n");
    }

    if (nowNum > maxNum)
    {
      maxNum = nowNum;
      counter = 1;
    }
    else if (nowNum == maxNum)
    {
      ++counter;
    }
  }
  
  size_t get_result() const
  {
    return counter;
  }

private:
  size_t counter;
  size_t maxNum;
  size_t nowNum;
};


int main()
{
  int nowNum = 0;
  std::cin >> nowNum;

  if (!std::cin)
  {
    std::cerr << "Bad input, try again\n";
    return 1;
  }
  else if (nowNum == 0)
  {
    std::cout << "There are no numbers in the sequence, the number of maximum numbers: 0\n"; 
    return 0;
  }
  SequenceNumOfMax counter;
  counter.start_max(nowNum);

  do
  {
    std::cin >> nowNum;
    if (!std::cin)
    {
      std::cerr << "Bad input, try again\n";
      return 1;
    }
    else if (nowNum != 0)
    {
      try
      {
        counter.count(nowNum);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (nowNum != 0);
  std::cout << counter.get_result() << "\n";
  return 0;
}
