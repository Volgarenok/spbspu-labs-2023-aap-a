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
  while (c_number != 0)
  {
    std::cin >> c_number;
    if (!std::cin)
    {
      std::cerr << "not a number was inputed\n"; 
      return 1; 
    }
  }
}
