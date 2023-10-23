#include <iostream>

int main()
{
  int number = 0;
  do{
    std::cin >> number;
    if (!std::cin){
      std::cerr << "This is not a sequence\n";
      return 1;
    }
  }
  while (number != 0);
}
