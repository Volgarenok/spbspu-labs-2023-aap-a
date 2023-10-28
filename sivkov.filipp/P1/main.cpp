#include <iostream>
#include <limits>
int main()
{
  int num = 0;
  size_t k =0;
  do
  {
    std::cin >> num;
    if (!std::cin)
    {
      std::cerr << "is not a seq...\n";
      return 1;
    }
    else if (num !=0)
    {
      size_t max_size = std::numeric_limits < size_t > ::max();
      if (k == max_size)
      {
        std::cout << "seq is too long\n";
        return 2;
      }
    }
  }
  while(num != 0);
  std::cout << k << std::endl;
}
