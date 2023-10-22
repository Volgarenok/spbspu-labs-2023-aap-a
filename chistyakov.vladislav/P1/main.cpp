#include<iostream>

int main()
{
  int max_num = 0;
  int counter = 0;

  while (true)
  {
    int num = 0;
    std::cin >> num;

    if (!std::cin){
      std::cout << "Bad input, try again!";
      return 1;
    }

    if (num == max_num){
      counter += 1;
    }
    else if (num > max_num){
      max_num = num;
      counter = 1;
    }

    if (num == 0){
      if (max_num == 0){
        std::cout << 0  << "\n";
        break;
    }
      std::cout << counter << "\n";
      break;
    }
  }
  return 0;
}
