#include <iostream>

int main()
{
    int num = 0;
    std::cin >> num;
    if(!std::cin){
        std::cerr << "Is not a number\n";
        return 1;
    }
    return 0;
}