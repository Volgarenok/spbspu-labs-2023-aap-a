#include <iostream>
#include <limits>

namespace isaychev
{
  struct even_counter
  {
    even_counter():
     count(0)
     max_count(0)
    {}
    void evn_cnt()
    {}
    unsigned long long int get_res()
    {}

    private:
    unsigned long long int count;
    unsigned long long int max_count;
  };
}

int main()
{
  int c_number = 0;
  std::cin >> c_number;
  if (!std::cin)
  {
    std::cerr << "not a number was inputed\n";
    return 1;
  }
  while (c_number != 0)
  {
    unsigned long long int u_border = std::numeric_limits <unsigned long long int>::max();
    if (count == u_border)
    {
      std::cerr << "sequence is too long\n";
      return 2;
    }
    else if (c_number % 2 == 0)
    {
      ++count;
      if (count > max_count)
      {
        max_count = count;
      }
    }
    else if (c_number % 2 != 0)
    {
      count = 0;
    }
    std::cin >> c_number;
    if (!std::cin)
    {
      std::cerr << "not a number was inputed\n";
      return 1;
    }
  }
  std::cout << max_count << "\n";
}


