#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <string>
#include <cstddef>

namespace shabalin
{

class Checker
{
public:
    Checker(const std::string& string);
    Checker& operator>>(std::string& string);
    Checker& operator>>(double& d);
    operator bool() const;
private:
    std::string findNextToken();
    bool isOk_;
    std::string string_;
    size_t begin_, end_;
};

}
#endif
