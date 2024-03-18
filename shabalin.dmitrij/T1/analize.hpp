#ifndef ANALIZE_HPP
#define ANALIZE_HPP
#include <string>
#include <cstddef>

namespace shabalin
{

class Analize
{
public:
    Analize(const std::string& string);
    Analize& operator>>(std::string& string);
    Analize& operator>>(double& d);
    operator bool() const;
private:
    std::string findToken();
    bool isOk_;
    std::string string_;
    size_t begin_, end_;
};

}
#endif
