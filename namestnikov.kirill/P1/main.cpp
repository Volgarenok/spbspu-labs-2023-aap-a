#include <iostream>

int main()
{
  int lastnumber = 0;
  std::cin >> lastnumber;
  if (!std::cin)
  {
    std::cerr << "Is not a  sequence\n";
    return 1;
  }
  else if (lastnumber == 0)
  {
    std::cerr << "There is no way to find a local min\n";
    return 2;
  }
}
