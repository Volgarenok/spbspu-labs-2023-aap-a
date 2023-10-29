#include <iostream>
#include <limits>
#include <stdexcept>

class LocalMaxCounter
{
public:
  LocalMaxCounter(long long int firstNumber, long long int secondNumber);
  void count(long long int number);
  size_t get_result() const;
private:
  long long int prevNumber;
  long long int currentNumber;
  long long int nextNumber;
  size_t count_;
};

LocalMaxCounter::LocalMaxCounter(long long int firstNumber, long long int secondNumber):
  prevNumber(firstNumber),
  currentNumber(secondNumber),
  nextNumber(1),
  count_(0)
{}

void LocalMaxCounter::count(long long int number)
{
  nextNumber = number;
  if (currentNumber > prevNumber && currentNumber > nextNumber)
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (count_ == max_size)
    {
      throw std::logic_error("sequence is too long");
    }
    ++count_;
  }
prevNumber = currentNumber;
currentNumber = nextNumber;
}

size_t LocalMaxCounter::get_result() const
{
  return count_;
}

int main()
{
  long long int firstNumber = 1;
  long long int secondNumber = 1;
  long long int number = 1;

  std::cin >> firstNumber;
  if (!std::cin)
  {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  else if (firstNumber == 0)
  {
    std::cerr << "A sequence is too short \n";
    return 2;
  }

  std::cin >> secondNumber;
  if (!std::cin)
  {
    std::cerr << "Is not a sequence\n";
    return 1;
  }
  else if (secondNumber == 0)
  {
    std::cout << 0 << '\n';
    return 0;
  }
  LocalMaxCounter counter(firstNumber, secondNumber);
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
        std::cerr << "Error: " << e.what() << '\n';
        return 2;
      }
    }
  }
  while (number != 0);

  std::cout << counter.get_result()  << '\n';
}
