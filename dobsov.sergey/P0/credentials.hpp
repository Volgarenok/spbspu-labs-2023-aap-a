#ifndef CREDENTIALS_HPP
#define CREDENTIALS_HPP
#include <string>
namespace dobsov
{
  struct Credentials
  {
    std::string first;
    std::string second;
  };
  void outCredentials(const Credentials & cr);
}
#endif
