#include <iostream>

int main()
{
  int arrayElements[3] = {0, 0, 0};
  for (int i = 0; i < 3; ++i)
  {
    std::cin >> arrayElements[i];
    if (std::cin.fail() || (arrayElements[i] == 0))
    {
      std::cout << "0\n";
      return 0;
    }
  }
  int counter = 0;
  while (!std::cin.eof() && (arrayElements[2] != 0))
  {
    counter += (arrayElements[0] > arrayElements[1]) && (arrayElements[1] > arrayElements[2]);
    arrayElements[0] = arrayElements[1];
    arrayElements[1] = arrayElements[2];
    std::cin >> arrayElements[2];
  }
  if (arrayElements[2] == 0)
  {
    std::cout << counter << '\n';
    return 0;
  }
  else
  {
    std::cout << "0\n";
    return 0;
  }
}
