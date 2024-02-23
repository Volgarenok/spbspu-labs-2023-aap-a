#include "mergeTwoLines.h"
#include "transformInputString.h"

char* skuratov::mergeTwoLines(char* result, const char* inputLine, const char* lineOfProgram)
{
  char* resultPtr = result;

  while (*inputLine != '\0' || *lineOfProgram != '\0')
  {
    if (*inputLine != '\0')
    {
      *resultPtr = *inputLine;
      ++resultPtr;
      ++inputLine;
    }
    if (*lineOfProgram != '\0')
    {
      *resultPtr = *lineOfProgram;
      ++resultPtr;
      ++lineOfProgram;
    }
  }
  *resultPtr = '\0';
  return result;
}
