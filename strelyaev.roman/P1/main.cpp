#include <iostream>

int main()
{
  int currentNumber = 0;
/* В голову ничего кроме самого обычно do-while цикла не пришло. Извиняйте */
  do 
  {
    std::cin >> currentNumber;

    if (!std::cin)
    {
    std::cerr << "AN ERROR HAS OCCURRED\n";
    return 1;
    }
  }
  while (currentNumber != 0); 
}

