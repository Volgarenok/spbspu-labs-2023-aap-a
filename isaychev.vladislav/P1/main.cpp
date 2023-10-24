#include <iostream>

int main()
{
  int c_number = 0;
  std::cin >> c_number;
  if (!std::cin)
  {
    std::cerr << "not a number was inputed\n";
    return 1;
  }
  unsigned long long int count = 0, max_count = 0;
  while (c_number != 0)
  {
    if (c_number % 2 == 0) 
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


