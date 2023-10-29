#ifndef CREDENTIALS_HPP
#define  CREDENTIALS_HPP
#include <string>
namespace serter
{
    struct Credentials 
    {
       std::string first;
        std::string second;
   };   
      void outCredentials(const Credentials & cr); 
}
#endif
