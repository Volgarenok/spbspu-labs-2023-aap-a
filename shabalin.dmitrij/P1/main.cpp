#include <iostream>

int main()
{
  int CurNum = 0;
  std::cin >> CurNum;
  if (!std::cin)
  {
    std::cerr << ("Is not a sequence\n");
    return 1;
  }

}