#include <iostream>
#include <limits>
#include <stdexcept>

struct SequenceCounter
{
  SequenceCounter():
   count(0)
  {}

  void size(int num)
  {
     size_t max_s = std::numeric_limits< size_t >::max();
      if (count == max_s)
      {
        throw  std::logic_error("Sequence is too long!\n");
      }
      ++count;
  }
  size_t get_res() const
  {
    return count;
  }
private:
  size_t count;
};

int main()
{
  int num = 0;
  SequenceCounter counter;
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
      try
      {
        counter.size(num);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
    }
  }

  while (num != 0);
  std::cout << counter.get_res() << "\n";
}
