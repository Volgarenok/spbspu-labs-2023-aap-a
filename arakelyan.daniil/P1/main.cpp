#include <iostream>
#include <limits>

bool quotientOfNumbers(int a,int b);

int main()
{
  size_t count = 0;
  int num = 0;
  size_t lenght = 0;
  do
  {
    int past = num;
    std::cin >> num;
    if (!std::cin) {
      std::cerr << "Not a num.\n";
      return 1;
    }
    else if (num != 0) {
      size_t max_lenght  = std::numeric_limits<size_t>::max();
      if(lenght == max_lenght)
      {
        std::cerr << "Sequence is too long.\n";
        return 2;
      } else if (quotientOfNumbers(num,past)) {
        ++count;
        ++lenght;
      }
    }
  }
  while (num != 0);
  if (count == 0) {
    std::cerr << "Sequence is too small.\n";
    return 2;
  } else {
    std::cout << count << "\n";
  }
  return 0;
}

bool quotientOfNumbers(int a,int b){
  if (a % b == 0) {
    return true;
  }
  return false;
}; 
