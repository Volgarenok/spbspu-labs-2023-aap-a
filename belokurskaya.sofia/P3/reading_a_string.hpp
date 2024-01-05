#ifndef READING_A_STRING_HPP
#define READING_A_STRING_HPP

#include <iostream>
#include <stdexcept>

char * resizeStringBuffer(const char * my_string, const size_t size, const size_t new_memory);

char * inputString(std::istream& input);

#endif
