#include "is_numeric.hpp"
#include <cstddef>

bool erohin::isNumeric(char * str)
{
   size_t i = 0;
   while(str[i] != '\0')
   {
      if(str[i] < '0' || str[i] > '9')
      {
         return false;
      }
      ++i;
   }
   return (i > 0);
}
