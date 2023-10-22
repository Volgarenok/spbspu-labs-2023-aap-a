#include <iostream>
#include <limits>

int main()
{
  size_t count = 0;
  int num = 0;
  size_t lenght = 0;
  do {
    int past = num;
    std::cin >> num;
    if(!std::cin){
      std::cerr << "Not a num\n";
      return 1;
    }else if (num != 0)
    {
      size_t max_lenght  = std::numeric_limits<size_t>::max();
      if(lenght == max_lenght)
      {
        std::cerr << "Sequence is too long\n";
        return 2;
      }else if(num % past == 0){
        ++count;
        ++lenght;
      }
    }
    else
    {
      std::cout << "Sequence is too small\n";
      return 2;
    }
  }while (num != 0);
  std::cout << count << "\n";
  return 0;
}
