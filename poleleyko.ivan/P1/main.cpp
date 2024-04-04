#include <iostream>
#include <limits>

int main()
{
  int max = std::numeric_limits< int >::min();
  int secMax = std::numeric_limits< int >::min();

  std::cout << "Введите последовательность чисел: ";
  int num = 0;
  bool hasInput = false;

  while (std::cin >> num)
  {
    if (num == 0)
    {
      break;
    }
    hasInput = true;
    if (num > max)
    {
      secMax = max;
      max = num;
    }
    else if (num > secMax && num != max)
    {
      secMax = num;
    }
  }
  if (!hasInput)
  {
    std::cerr << "Ошибка! Пустая последовательность.\n";
    return 2;
  }

  std::cout << "Второе число по величине: ";
  if (secMax == std::numeric_limits< int >::min())
  {
    std::cout << 0 << "\n";
  }
  else
  {
    std::cout << secMax << "\n";
  }

  return 0;
}
