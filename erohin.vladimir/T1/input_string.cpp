#include "input_string.hpp"
#include <iostream>

char* erohin::inputString(std::istream& input, char* str)
{
    const size_t iter_size = 20;
    size_t size = 0;
    char elem = 0;
    size_t i = 0;
    char* temp = nullptr;
    input >> std::noskipws;
    while (input >> elem)
    {
        if (size == i)
        {
            temp = resize(str, size, iter_size);
            size += iter_size;
            delete[] str;
            str = temp;
        }
        str[i++] = elem;
        if (elem == '\n')
        {
            str[i - 1] = '\0';
            break;
        }
        if (!input)
        {
            throw std::logic_error("Wrong string input\n");
        }
    }
    input >> std::skipws;
    return str;
}

char* erohin::resize(char* str, size_t size, size_t shift)
{
    char* resized = new char[size + shift + 1]{};
    for (size_t i = 0; i < size; ++i)
    {
        resized[i] = str[i];
    }
    resized[size + shift] = '\0';
    return resized;
}
