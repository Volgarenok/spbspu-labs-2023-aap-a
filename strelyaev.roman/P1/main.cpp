#include <iostream>
#include "mondec.h"

int main()
{
  using namespace strelyaev;
  int currentNumber;
  Mondec count;
/* В голову ничего кроме самого обычно do-while цикла не пришло. Извиняйте */
  do
  {
    std::cin >> currentNumber;
    if (!std::cin)
    {
      std::cerr << "AN ERROR HAS OCCURRED: NOT A NUMBER\n";
      return 1;
    }
    else if (currentNumber != 0)
    {
      try
      {
        count.numberCheck(currentNumber);
        count.counterCheck();
      }
      catch (std::exception & e)
      {
        std::cerr << "ERROR: " << e.what() << "\n";
        return 2;
      }
    }
  }
  while (currentNumber != 0);
  std::cout << count.resultlog() << "\n";
}

