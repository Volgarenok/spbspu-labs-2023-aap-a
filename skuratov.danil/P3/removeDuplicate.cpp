#include "removeDuplicate.h"
#include "transformInputString.h"

char* skuratov::removeDuplicate(char* result, const char* lineOfProgram, const char* lineOfInput)
{
  char* resPtr = result;
  const char* inputPtr = lineOfInput;

  while (*inputPtr != '\0')
  {
    const char* programPtr = lineOfProgram;
    bool isDuplicate = false;

    while (*programPtr != '\0')
    {
      if (*inputPtr == *programPtr)
      {
        isDuplicate = true;
        break;
      }
      ++programPtr;
    }

    if (!isDuplicate)
    {
      *resPtr = *inputPtr;
      ++resPtr;
    }
    ++inputPtr;
  }
  *resPtr = '\0';
  return result;
}
