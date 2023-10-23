#include <iostream>
#include <limits>

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
  int currentnumber = 0;
  std::cin >> currentnumber;
  if (!std::cin)
  {
    std::cerr << "Is not a  sequence\n";
    return 1;
  }
  else if (currentnumber == 0)
  {
    std::cerr << "There is no way to find a local min\n";
    return 2;
  }
  int futurenumber = 0;
  std::cin >> futurenumber;
  if (!std::cin)
  {
    std::cerr << "Is not a  sequence\n";
    return 1;
  }
  else if (futurenumber == 0)
  {
    std::cerr << "There is no way to find a local min\n";
    return 2;
  }
  size_t counter = 0;
  while (futurenumber != 0)
  {
    if ((currentnumber < lastnumber) && (currentnumber < futurenumber))
    {
      size_t max_size = std::numeric_limits< size_t >::max();
      if (counter == max_size)
      {
        std::cerr << "Sequence is too long\n";
        return 2;
      }
      ++counter;
    }
    lastnumber = currentnumber;
    currentnumber = futurenumber;
    std::cin >> futurenumber;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
  }
  std::cout << counter << std::endl;
}
