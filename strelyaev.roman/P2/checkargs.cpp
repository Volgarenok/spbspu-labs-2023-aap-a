#include "checkargs.h"
void checkArgs(int argc, char * argv[], int n, std::fstream & in)
{
  if (argc != 4)
  {
    throw (std::invalid_argument("Must be 3 arguments: task, input_file, output_file"));
  }
  if ((n < 1) || (n > 2))
  {
    throw (std::invalid_argument("first argument out of range"));
  }
  if (!in)
  {
    throw (std::logic_error("Unable to read input file"));
  }
}

