#include "tokenizer.hpp"
#include <cstddef>

namespace shabalin
{

Tokenizer::Tokenizer(const std::string& string)
{
    string_ = string;
    begin_ = end_ = 0;
    isOk_ = true;
}
std::string Tokenizer::findNextToken()
{
    constexpr char spaceSymbol = ' ';
    begin_ = string_.find_first_not_of(spaceSymbol, end_);
    end_ = string_.find_first_of(spaceSymbol, begin_);
    size_t tokenSize = end_ == std::string::npos ? std::string::npos : end_ - begin_;
    return string_.substr(begin_, tokenSize);
}
Tokenizer& Tokenizer::operator>>(std::string& string)
{
    std::string s = findNextToken();
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
Tokenizer& Tokenizer::operator>>(double& d)
{
    std::string s = findNextToken();
    if (s.empty())
    {
        isOk_ = false;
    }
    else
    {
        char* endPtr;
        d = std::strtod(s.c_str(), &endPtr);
        if (*endPtr != '\0')
        {
            isOk_ = false;
        }
    }
    return *this;
}
Tokenizer::operator bool() const
{
    return isOk_;
}
}
