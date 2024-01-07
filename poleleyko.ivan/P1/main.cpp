#include <iostream>
#include <climits>

int main ()
{
  int max = INT_MIN;
  int secMax = INT_MIN;

  std::cout << "Введите последовательность чисел: ";
  int num;
  bool hasInput = false;

  while (std::cin >> num){
    hasInput = true;
    if (num == 0) {
      if(!hasInput) {
        std::cerr << "Ошибка! Пустая последовательность.\n" << std::endl;
        return 2;
      }
      break;
    }
    if (num > max){
      secMax = max;
      max = num;

    } else if(num > secMax && num != max){
      secMax = num;
    }
  }
  if (!hasInput){
    std::cerr << "Ошибка! Пустая последовательность.\n";
    return 2;
  }
  std::cout << "Второе число по величине: ";
  if(secMax == INT_MIN){
    std::cout << 0 << std::endl;
  } else{
    std::cout << secMax << std::endl;
  }
  return 0;
}
