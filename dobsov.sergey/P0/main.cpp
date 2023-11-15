#include <iostream>
#include "credentials.hpp"

int main()
{
  using namespace dobsov;
  outCredentials(Credentials{"sergey", "dobsov"});
  std::cout << "\n";
}
