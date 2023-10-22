#include <iostream>

int main()
{
  unsigned long long count = 0;
  int num = 0;
  do {
    int past = num;
    std::cin >> num;
    if(!std::cin){
      std::cerr << "Not a num\n";
      return 1;
    }else if (num != 0)
    {
      if(num % past == 0)
      {
        ++count;
      }
    }
  }while (num != 0);
  std::cout << count << "\n";
  return 0;
}
