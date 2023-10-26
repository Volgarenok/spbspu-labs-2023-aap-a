#include <iostream>

int main()
{
    int number = 0;
    size_t size = 0;

    do 
    {
        std::cin >> number;
        if (!std::cin) {
            std::cerr << "sequence is not valid\n";
            return 1;
        }

        if (number != 0) {
            size++;
        }
    }
    while (number != 0);
    
    std::cout << size << std::endl;

    return 0;
}
