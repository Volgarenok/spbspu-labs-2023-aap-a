#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>

namespace skuratov
{
  struct Parameters
  {
    enum class Task
    {
      First,
      Second
    };
    Task task;
    std::string inputFileName;
    std::string outputFileName;
  };
  Parameters readParameters(int argc, char* argv[]);
}
#endif
