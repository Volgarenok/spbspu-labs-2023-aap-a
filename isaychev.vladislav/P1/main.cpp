#include <iostream>
#include <limits>

int main()
{
  int c_number = 0;
  std::cin >> c_number;
  if (!std::cin)
  {
   std::cerr << "not a number was inputed\n";
   return 1;
  }
  int p_number = 0;
  unsigned long long int count = 0, max_count = 0;
  while (c_number != 0)
  {
    if (!std::cin)
    {
      std::cerr << "not a number was inputed\n";
      return 1;
    }
    else if (std::cin)
    {
      if (p_number != 0 && (p_number % 2 == 0 && c_number % 2 == 0))
      {
        ++count;
        if (count > max_count)
        {
          max_count = count;
        }
      }
      else if (p_number != 0 && (p_number % 2 != 0 || c_number % 2 != 0))
      {
        count = 0;
      }
      p_number = c_number;
    }
    std::cin >> c_number;
  }
  const int ptn = 1;
  if (max_count > 0)
  {
    std::cout << max_count + ptn << "\n";
  }
  else
  {
    std::cout << max_count << "\n";
  }
}
