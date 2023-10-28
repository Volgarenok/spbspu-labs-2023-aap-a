#include <iostream>
#include <limits>
#include <stdexcept>
struct SeqCount
{
  SeqCount():
    k1(0)
  {}

  void k(int num, int num_old)
  {
    size_t max_size = std::numeric_limits < size_t > ::max();
    if (k1 == max_size)
    {
      throw std::logic_error("seq is to long");
    }
    if (num_old % num == 0)
    {
      ++k1;
    }
  }
  size_t get_result() const
  {
    return k1;
  }
private:
  size_t k1;
};

int main()
{
  int num = 0;
  int num_old = 0;
  SeqCount counter;
  do
  {
    num_old = num;
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "is not a seq...\n";
      return 1;
    }
    else if (num !=0)
    {
      try
      {
        counter.k(num, num_old);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error:" << e.what() << "\n";
        return 2;
      }
    }
  }
  while(num != 0);
  std::cout << "answ" <<counter.get_result() - 1 << std::endl;
}
