#include "analize.hpp"
#include <cstddef>
#include <string>

namespace shabalin
{
  Analize::Analize(const std::string &string)
  {
    string_ = string;
    begin_ = end_ = 0;
    isOk_ = true;
  }
  std::string Analize::findToken()
  {
    constexpr char spaceSymbol = ' ';
    begin_ = string_.find_first_not_of(spaceSymbol, end_);
    end_ = string_.find_first_of(spaceSymbol, begin_);
    if (end_ == std::string::npos)
    {
      std::string::npos;
    }
    else
    {
      end_ - begin_;
    }
    size_t sizeOftoken = end_;
    return string_.substr(begin_, sizeOftoken);
  }

  Analize &Analize::operator>>(std::string &string)
  {
    std::string s = findToken();
    if (s.empty())
    {
      isOk_ = false;
    }
    else
    {
      string = std::move(s);
    }
    return *this;
  }

  Analize &Analize::operator>>(double &d)
  {
    std::string s = findToken();
    if (s.empty())
    {
      isOk_ = false;
    }
    else
    {
      char *endPtr;
      d = std::strtod(s.c_str(), &endPtr);
      if (*endPtr != '\0')
      {
        isOk_ = false;
      }
    }
    return *this;
  }
  Analize::operator bool() const
  {
    return isOk_;
  }
}
