#include <iostream>

int main()
{
    int num = 0;
    std::cin >> num;
    if(!std::cin)
    {
        std::cerr << "Is not a number\n";
        return 1;
    }
    int count = 0;
    while(num != 0)
    {
        int past = num;
        std::cin >> num;
        if (num % past == 0)
        {
            std::cout << num << ":" << past  << ":" << count << "\n";
            count += 1;
        }
    }
    std::cout << count << "\n";
    return 0;
}