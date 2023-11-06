#include "credentials.hpp"
#include <iostream>
void dobsov::outCredentials(const Credentials & cr)
{
  std::cout << cr.second << "." << cr.first;
}
