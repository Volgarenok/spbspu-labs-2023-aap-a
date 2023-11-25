#include "credentials.hpp"
#include <iostream>
void serter::outCredentials(const Credentials & cr)
{
    std::cout << cr.second << "." << cr.first;
}
