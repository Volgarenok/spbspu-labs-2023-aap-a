#include "parameters.h"

#include <fstream>
#include <cstring>
#include <iostream>
#include <stdexcept>

namespace skuratov
{
  Parameters readParameters(int argc, char* argv[])
  {
    Parameters parameters;
    if (argc > 4)
    {
      throw std::invalid_argument("Too many arguments");
    }
    else if (argc < 4)
    {
      throw std::invalid_argument("Not enough arguments");
    }
    int taskNum = std::atoi(argv[1]);
    if (taskNum == 1)
    {
      parameters.task = Parameters::Task::First;
    }
    else if (taskNum == 2)
    {
      parameters.task = Parameters::Task::Second;
    }
    else
    {
      throw std::invalid_argument("First parameter is out of range");
    }
    parameters.inputFileName = argv[2];
    std::fstream in(parameters.inputFileName);
    if (!in)
    {
      throw std::invalid_argument("Input file with given name doesn't exist");
    }
    parameters.outputFileName = argv[3];
    return parameters;
  }
}
