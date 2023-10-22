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
  }while (num != 0);
  if(count == 0){
    std::cerr << "Sequence is too small\n";
    return 2;
  }else{
    std::cout << count << "\n";
  }
  return 0;
}
