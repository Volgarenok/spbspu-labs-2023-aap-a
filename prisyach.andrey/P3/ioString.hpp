#ifndef IOSTRING_HPP
#define IOSTRING_HPP

#include <iostream>

namespace prisyach
{

char* inputTheString(std::istream& inp, size_t& size);

void outputTheString(char* string, size_t size);

}

#endif
