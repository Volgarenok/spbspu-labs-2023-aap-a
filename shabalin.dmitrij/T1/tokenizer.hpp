#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <cstddef>

namespace shabalin
{

class Tokenizer
{
public:
    Tokenizer(const std::string& string);
    Tokenizer& operator>>(std::string& string);
    Tokenizer& operator>>(double& d);
    operator bool() const;
private:
    std::string findNextToken();
    bool isOk_;
    std::string string_;
    size_t begin_, end_;
};

}
#endif
