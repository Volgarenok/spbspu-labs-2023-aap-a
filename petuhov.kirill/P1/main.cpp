#include <iostream>

int main()
{
  int num = 0;
  int temp_count = 0;
  int max_count = 0;

  while (true)
  {
    std::cin >> num;

    if (!std::cin)
    {
      std::cerr << "Input is not a valid number!" << std::endl;
      return 1;
    }

    if (num == 0)
    {
      break;
    }

    if (num % 2 == 0)
    {
      ++temp_count;
      max_count = max_count < temp_count ? temp_count : max_count;
    }
    else
    {
      temp_count = 0;
    }
  }

  std::cout << max_count << std::endl;
}